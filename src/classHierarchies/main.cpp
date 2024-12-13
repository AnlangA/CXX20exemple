import <iostream>;
class PowerSource {
protected:
    int power;
public:
    PowerSource(int p) : power(p) {}
    virtual int getPower() const { return power; }
};

// Using virtual inheritance
class Battery : virtual public PowerSource {
public:
    Battery(int p) : PowerSource(p) {}
};

class Solar : virtual public PowerSource {
public:
    Solar(int p) : PowerSource(p) {}
};

class HybridDevice : public Battery, public Solar {
public:
    // Only one copy of PowerSource exists
    HybridDevice(int bp, int sp) : PowerSource(bp + sp), Battery(bp), Solar(sp) {}

    int getTotalPower() const {
        return getPower(); // No ambiguity
    }
};
int main() {
    PowerSource source(50);
    std::cout << "PowerSource power: " << source.getPower() << std::endl;

    Battery battery(100);
    std::cout << "Battery power: " << battery.getPower() << std::endl;

    Solar solar(150);
    std::cout << "Solar power: " << solar.getPower() << std::endl;

    HybridDevice hybrid(100, 200);
    std::cout << "Hybrid total power: " << hybrid.getTotalPower() << std::endl;

    return 0;
}
