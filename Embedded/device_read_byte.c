#define READ_SIZE (512)

size_t read(uint8_t* buf);

typedef struct 
{
    uint16_t read_pointer;
    uint8_t buf[READ_SIZE];
} helper_t;

helper_t read_helper;

void read_bytes_init(helper_t* helper)
{
    helper->read_pointer = 0;
}
size_t read_bytes(helper_t* helper, uint8_t* buf, size_t count)
{
    size_t write_pointer = 0;
    if (helper->read_pointer > 0)
    {
        write_pointer = min(count, (READ_SIZE - helper->read_pointer));
        memcpy(buf, helper->buf + helper->read_pointer, write_pointer);
        helper->read_pointer = (helper->read_pointer + write_pointer) & (READ_SIZE - 1);
    }
    while ((count - write_pointer) >= READ_SIZE)
    {
        write_pointer += read(buf + write_pointer);
    }
    if ((count - write_pointer) > 0)
    {
        read(helper->buf);
        memcpy(buf + write_pointer, helper->buf, (count - write_pointer));
        helper->read_pointer += (count - write_pointer);
    }
    return count;
}

read_bytes_init(&read_helper);
read_bytes(&read_helper, buffer, 10);
read_bytes(&read_helper, buffer, 1500);
read_bytes(&read_helper, buffer, 100);
