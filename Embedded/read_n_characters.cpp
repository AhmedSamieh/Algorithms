// Forward declaration of the read4 API.
int read4(char *buf);
#define READ_SIZE (4)
class Solution {
    char read_buf[READ_SIZE];
    int  read_pointer;
    int  end_pointer;
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    Solution() : read_pointer(0) {}
    int read(char *buf, int n) {
        int write_pointer = 0;
        if (read_pointer > 0)
        {
            write_pointer = min(n, (end_pointer - read_pointer));
            memcpy(buf, read_buf + read_pointer, write_pointer);
            read_pointer = (read_pointer + write_pointer);
            if (read_pointer == end_pointer)
            {
                read_pointer = 0;
            }
        }
        while ((n - write_pointer) >= READ_SIZE)
        {
            int number_of_actual_read = read4(buf + write_pointer);
            write_pointer += number_of_actual_read;
            if (number_of_actual_read < READ_SIZE)
            {
                return write_pointer;
            }
        }
        if ((n - write_pointer) > 0)
        {
            int number_of_actual_read;
            end_pointer = read4(read_buf);
            number_of_actual_read = min(end_pointer, (n - write_pointer));
            memcpy(buf + write_pointer, read_buf, number_of_actual_read);
            write_pointer += number_of_actual_read;
            read_pointer += number_of_actual_read;
            if (read_pointer == end_pointer)
            {
                read_pointer = 0;
            }
        }
        return write_pointer;
    }
};