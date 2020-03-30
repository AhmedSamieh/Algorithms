#include <iostream>
#include <string>

using namespace std;

class Image {
public:
    string timestamp;
    string extension;
    size_t index; // input order
    Image* next;
    Image() : next(NULL) {}
    Image(string& timestamp, string& extension, size_t index, Image* next)
    : timestamp(timestamp), extension(extension), index(index), next(next) {
    }
};
class City {
public:
    string name;
    int    number_of_images;
    Image* image;
    City*  next;
    
    City() : number_of_images(0), image(NULL), next(NULL) {}
    City(string& name) : name(name), number_of_images(0), image(NULL), next(NULL) {}
};
enum {
    START_OF_LINE,
    GET_EXTENSION,
    GET_CITY,
    GET_TIMESTAMP
};
const int number_of_letters = 26;
void int_to_zero_padded_string(char *str, int size, int num) {
    for (int i = size - 1; i >= 0; --i) {
        str[i] = '0' + (num % 10);
        num /= 10;
    }
}
void insert_into_data_structure(City **cities, string &extension, string &city_name, string &timestamp, size_t index) {
    City** pp_city = &cities[static_cast<int>(city_name[0] - 'A')];
    City* p_city = NULL;
    while (NULL != *pp_city) {
        if ((*pp_city)->name == city_name) {
            p_city = (*pp_city);
            break;
        }
        pp_city = &(*pp_city)->next;
    }
    if (NULL == p_city) {
        *pp_city = p_city = new City(city_name);
    }
    // we have city node, insert file entry in order
    p_city->number_of_images++;
    Image** pp_image = &p_city->image;
    while (NULL != *pp_image && (*pp_image)->timestamp <= timestamp) {
        pp_image = &(*pp_image)->next;
    }
    *pp_image = new Image(timestamp, extension, index, *pp_image);
}
void generate_new_format(string *output_files_inorder, City **cities) {
    for (int i = 0; i < number_of_letters; ++i) {
        for (City *city = cities[i]; NULL != city; city = city->next) {
            int num_of_imgs = city->number_of_images;
            int num_of_digits = 1;
            while ((num_of_imgs /= 10) > 0) {
                ++num_of_digits;
            }
            char *zero_padded_str = new char[num_of_digits + 1];
            zero_padded_str[num_of_digits] = 0;
            int image_number = 1;
            for (Image* image = city->image; NULL != image; image = image->next) {
                int_to_zero_padded_string(zero_padded_str, num_of_digits, image_number++);
                output_files_inorder[image->index] = city->name + string(zero_padded_str) + "." + image->extension + "\n";
            }
            delete[] zero_padded_str;
        }
    }
}
void delete_data_structure(City **cities) {
    for (int i = 0; i < number_of_letters; ++i) {
        City *prev_city = NULL;
        for (City *city = cities[i]; NULL != city; city = city->next) {
            Image *prev_image = NULL;
            for (Image* image = city->image; NULL != image; image = image->next) {
                if (NULL != prev_image) {
                    delete prev_image;
                }
                prev_image = image;
            }
            if (NULL != prev_image) {
                delete prev_image;
            }
            if (NULL != prev_city) {
                delete prev_city;
            }
            prev_city = city;
        }
        if (NULL != prev_city) {
            delete prev_city;
        }
    }
}
string solution(string &S) {
    City **cities = new City*[number_of_letters]; // hash with 1st character in City
    for (size_t i = 0; i < number_of_letters; ++i) {
        cities[i] = NULL;
    }
    int state = START_OF_LINE;
    string extension;
    string city;
    string timestamp;
    size_t total_number_of_images = 0;
    // split by \n into string[]
    // split by ", " to get filename, city, date time
        // split by . to get ext
    // for each line, search for position in hash table of pointer to list
    // inser in the list, datetime and ext
    for (size_t i = 0; i < S.size(); ++i) {
        switch (state) {
            case START_OF_LINE:
                if ('.' == S[i]) {
                    state = GET_EXTENSION;
                }
                break;
            case GET_EXTENSION:
                if (',' == S[i]) {
                    state = GET_CITY;
                }
                else {
                    extension += S[i];
                }
                break;
            case GET_CITY:
                if (',' == S[i]) {
                    state = GET_TIMESTAMP;
                }
                else if (' ' != S[i]) {
                    city += S[i];
                }
                break;
            case GET_TIMESTAMP:
                if ('\n' == S[i]) {
                    // insert into the hash table
                    insert_into_data_structure(cities, extension, city, timestamp, total_number_of_images++);
                    // clear for the next file
                    extension.clear();
                    city.clear();
                    timestamp.clear();
                    state = START_OF_LINE;
                }
                else if ('-' != S[i] && ':' != S[i] && ' ' != S[i]) {
                    timestamp += S[i];
                }
                break;
            default:
                break;
        }
    }
    insert_into_data_structure(cities, extension, city, timestamp, total_number_of_images++);
    string *output_files_inorder = new string[total_number_of_images];
    generate_new_format(output_files_inorder, cities);
    string ret;
    for (size_t i = 0; i < total_number_of_images; ++i) {
        ret += output_files_inorder[i];
    }
    // free allocated memory
    delete[] output_files_inorder;
    delete_data_structure(cities);
    delete[] cities;
    return ret;
}
int main(void)
{
    string test_case = "photo.jpg, Warsaw, 2013-09-05 14:08:15\n"
                       "john.png, London, 2015-06-20 15:13:22\n"
                       "myFriends.png, Warsaw, 2013-09-05 14:07:13\n"
                       "Eiffel.jpg, Paris, 2015-07-23 08:03:02\n"
                       "pisatower.jpg, Paris, 2015-07-22 23:59:59\n"
                       "BOB.jpg, London, 2015-08-05 00:02:03\n"
                       "notredame.png, Paris, 2015-09-01 12:00:00\n"
                       "me.jpg, Warsaw, 2013-09-06 15:40:22\n"
                       "a.png, Warsaw, 2016-02-13 13:33:50\n"
                       "b.jpg, Warsaw, 2016-01-02 15:12:22\n"
                       "c.jpg, Warsaw, 2016-01-02 14:34:30\n"
                       "d.jpg, Warsaw, 2016-01-02 15:15:01\n"
                       "e.png, Warsaw, 2016-01-02 09:49:09\n"
                       "f.png, Warsaw, 2016-01-02 10:55:32\n"
                       "g.jpg, Warsaw, 2016-02-29 22:13:11";
    cout << test_case << endl;
    string ans = solution(test_case);
    cout << "return from solution" << endl;
    cout << ans << endl;
    return 0;
}