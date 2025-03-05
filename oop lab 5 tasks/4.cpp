#include <iostream>

using namespace std;

class Blend {
public:
    void blendJuice() {
        cout << "Blending juice...\n";
        for (long i = 0; i < 500000000; i++);  
        cout << "Blending complete!\n";
    }
};

class Grind {
public:
    void grindJuice() {
        cout << "Grinding juice...\n";
        for (long i = 0; i < 500000000; i++);
        cout << "Grinding complete!\n";
    }
};

class JuiceMaker {
private:
    Blend blender;
    Grind grinder;

public:
    void makeJuice() {
        blender.blendJuice();
        grinder.grindJuice();
        cout << "Juice is ready!\n";
    }
};

int main() {
    JuiceMaker myJuiceMaker;
    myJuiceMaker.makeJuice();
    return 0;
}
