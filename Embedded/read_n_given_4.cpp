// Forward declaration of the read4 API.
int read4(char *buf);

class Solution
{
    char buffer[4];
    int  buffer_index;
    int  buffer_size;
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    Solution() : buffer_index(0), buffer_size(0) {}
    int read(char *buf, int n)
    {
        int ret = 0;

        if (buffer_index > 0) {
            int size = min(n, buffer_size - buffer_index);

            for (int i = 0; i < size; ++i) {
                buf[i] = buffer[buffer_index++];
            }

            if (buffer_index == buffer_size) {
                buffer_index = 0;
                buffer_size = 0;
            }

            n -= size;
            ret += size;
        }

        while (n >= 4) {
            int size = read4(buf + ret);
            ret += size;
            n -= size;

            if (size != 4) {
                return ret;
            }
        }

        if (n > 0) {
            buffer_index = 0;
            buffer_size = read4(buffer);
            int size = min(n, buffer_size);

            for (int i = 0; i < size; ++i) {
                buf[ret + i] = buffer[buffer_index++];
            }

            if (buffer_index == buffer_size) {
                buffer_index = 0;
                buffer_size = 0;
            }

            n -= size;
            ret += size;
        }

        return ret;
    }
};