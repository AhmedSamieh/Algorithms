class TrafficLight {
    int                active_road;
    mutex              active_road_mutex;
public:
    TrafficLight() : active_road(1) {
    }

    void carArrived(
        int carId,                   // ID of the car
        int roadId,                  // ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
        int direction,               // Direction of the car
        function<void()> turnGreen,  // Use turnGreen() to turn light to green on current road
        function<void()> crossCar    // Use crossCar() to make car cross the intersection
    ) {
        unique_lock<mutex> guard(active_road_mutex);
        if (active_road != roadId)
        {
            turnGreen();
            active_road = roadId;
        }
        crossCar();
    }
};
