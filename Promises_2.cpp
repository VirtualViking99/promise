#include <iostream>
#include <functional>
#include <thread>
#include <future>
#include <stdexcept>

void print_int(std::future<int>& fut) 
{
    std::cout << "Waiting for value from print thread \n";
    std::cout << "Value: " << fut.get() << "\n";
}


int main()
{
    std::promise<int> prom;
    std::future<int> fut = prom.get_future();


    std::thread print_thread(print_int, std::ref(fut));


    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    std::cout << "Now setting the value in the main thread\n";
    prom.set_value(10);

    print_thread.join();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
