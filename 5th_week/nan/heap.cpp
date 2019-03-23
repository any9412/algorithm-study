#include <iostream>
#include <vector>

template <typename T>
class MaxHeap
{
public:
    MaxHeap()
        : heap({0})
    {
    }

    void insertMaxHeap(T item)
    {
        std::cout << __func__ << " item: " << item << std::endl;
        heap.push_back(item);
        int index = heap.size()-1;
        int parent = 0;
        while (true) {
            parent = index / 2;
            if (parent == 0) {
                break;
            }
            std::cout << "parent: " << parent << std::endl;
            if (heap.at(parent) < item) {
                heap.at(index) = heap.at(parent);
                heap.at(parent) = item;
                index = parent;
            } else {
                break;
            }
        }

        printHeap();
    }

    T deleteMaxHeap()
    {
        int index = 1;
        int child = 0;
        T root = heap.at(index);
        std::cout << __func__ << " root: " << root << std::endl;
        heap.at(index) = heap.at(heap.size()-1);
        heap.pop_back();
        while (true) {
            child = index * 2;
            if (heap.at(child) > heap.at(index)) {
                T tmp = heap.at(index);
                heap.at(index) = heap.at(child);
                heap.at(child) = tmp;
            } else {
                break;
            }
        }

        printHeap();
        return root;
    }

    void printHeap()
    {
        std::cout << __func__ << " heap size: " << heap.size()-1 << std::endl;
        for (auto it = heap.begin(); it != heap.end(); it++) {
            std::cout << (*it) << " ";
        }
        std::cout << std::endl;
    }
private:
    std::vector<T> heap;
};

int main()
{
    MaxHeap<int> maxHeap;
    maxHeap.insertMaxHeap(1);
    maxHeap.insertMaxHeap(2);
    maxHeap.insertMaxHeap(10);
    maxHeap.insertMaxHeap(5);
    maxHeap.insertMaxHeap(7);

    maxHeap.deleteMaxHeap();
    maxHeap.deleteMaxHeap();
    maxHeap.deleteMaxHeap();
}
