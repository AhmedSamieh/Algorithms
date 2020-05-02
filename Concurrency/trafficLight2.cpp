class TrafficLight
{
    int   active_road;
    mutex mtx;
    bool  binding_cars[2];
    int   crossing_cars;
    condition_variable cv;
public:
    TrafficLight() : active_road(1), crossing_cars(0)
    {
        binding_cars[0] = false;
        binding_cars[1] = false;
    }

    void carArrived(
        int carId,                   // ID of the car
        int roadId,                  // ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
        int direction,               // Direction of the car
        function<void()> turnGreen,  // Use turnGreen() to turn light to green on current road
        function<void()> crossCar    // Use crossCar() to make car cross the intersection
    )
    {
        mtx.lock();

        if (active_road != roadId) {
            if (crossing_cars == 0) {
                turnGreen();
                active_road = roadId;
            } else {
                mutex cv_mtx;
                unique_lock<mutex> lock(cv_mtx);
                int first_in_line = !binding_cars[roadId - 1];
                binding_cars[roadId - 1] = true;
                mtx.unlock();
                cv.wait(lock);
                mtx.lock();

                if (first_in_line) {
                    turnGreen();
                    active_road = roadId;
                    binding_cars[roadId - 1] = false;
                }
            }
        }

        crossing_cars++;
        mtx.unlock();
        crossCar();
        mtx.lock();
        crossing_cars--;

        if (crossing_cars == 0) {
            cv.notify_all();
        }

        mtx.unlock();
    }
};
