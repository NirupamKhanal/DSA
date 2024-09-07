#include <cstdlib>
#include <iostream>
#include <string>
#include <memory>

using namespace std; 

class Entity {
    public: 
        Entity() {
            cout << "Created Entity!" << endl; 
        }
        ~Entity() {
            cout << "Destroyed Entity!" << endl;
        }

        void Print() {}
};

int main() {

    shared_ptr<Entity> e0;
    {
        unique_ptr<Entity> entity(new Entity); // Unique Pointer
        entity -> Print(); 

        std::cin.get();

        shared_ptr<Entity> sharedEntity = make_shared<Entity>(); // Shared Pointer
        weak_ptr<Entity> weakEntity = sharedEntity; // Weak Pointer
        e0 = sharedEntity;
    }

    std::cin.get();
}