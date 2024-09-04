#include <iostream>

class smart_array {
    int* arr;
    int num;
    int count;
public:
    smart_array(int init_size) :num(init_size), count(0) {
        arr = new int[num];


    }
    smart_array(const smart_array& smart):num(smart.num),count(smart.count) {
        arr = new int[num];
        for (int i = 0;i < count;i++) {
            arr[i] = smart.arr[i];
        }

        
    }
        ~smart_array() {
        delete[] arr;
    }

        smart_array& operator=(const smart_array& smart) {
            if (this != &smart) {
                delete[] arr;
                num = smart.num;
                count = smart.count;

                arr = new int[num];
                for (int i = 0; i < count;i++) {
                    arr[i] = smart.arr[i];
                }
            }
            return *this;
        }

    int add_element(int value) {
        if (count >= num) {
            int* new_arr = new int[num * 2];
            for (int i = 0; i < num; i++) {
                new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
            num *= 2;
        }
        arr[count++] = value;
        return count - 1;
    }

    void print()const {
        
        for (int i = 0; i <count;i++) {
            std::cout << arr[i] << std::endl;
        }
    }


};



int main()
{
    smart_array arr(5);
    arr.add_element(1);
    arr.add_element(4);
    arr.add_element(155);

    smart_array new_array(2);
    new_array.add_element(44);
    new_array.add_element(34);

    arr = new_array;
    arr.print();

    return 0;
}

