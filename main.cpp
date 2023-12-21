#include <iostream>
#include <string>
#include <vector>

// Product class
class Computer {
public:
	void setCPU(const std::string& cpu) {
		cpu_ = cpu;
	}
	void setMemory(const std::string& memory) {
		memory_.push_back(memory);
	}
	void setStorage(const std::string& storage) {
		storage_ = storage;
	}
	void setType(const std::string& type) {
		type_ = type;
	}
	void display() {
		std::cout << "Type: " << type_ << std::endl;
		std::cout << "CPU: " << cpu_ << std::endl;
		std::cout << "Memory: ";
		for (auto m : memory_) {
			std::cout << " " << m;
		}
		std::cout << "\nStorage: " << storage_ << std::endl;
	}
private:
	std::string cpu_;
	std::vector<std::string> memory_;
	std::string storage_;
	std::string type_;
};
// Builder interface
class ComputerBuilder {
public:
	virtual void buildCPU(const std::string& cpu) = 0;
	virtual void buildMemory(const std::string& memory) = 0;
	virtual void buildStorage(const std::string& storage) = 0;
	Computer getResult() {
		return computer_;
	}
protected:
	Computer computer_;
};
// Concrete Builder
class DesktopComputerBuilder : public ComputerBuilder {
public:
	DesktopComputerBuilder() {
		computer_ = Computer();
		computer_.setType("Desktop");
	}
	void buildCPU(const std::string& cpu) override {
		computer_.setCPU(cpu);
	}
	void buildMemory(const std::string& memory) override {
		computer_.setMemory(memory);
	}
	void buildStorage(const std::string& storage) override {
		computer_.setStorage(storage);
	}
};
// Concrete Builder
class LaptopComputerBuilder : public ComputerBuilder {
public:
	LaptopComputerBuilder() {
		computer_ = Computer();
		computer_.setType("Laptop");
	}
	void buildCPU(const std::string& cpu) override {
		computer_.setCPU(cpu);
	}
	void buildMemory(const std::string& memory) override {
		computer_.setMemory(memory);
	}
	void buildStorage(const std::string& storage) override {
		computer_.setStorage(storage);
	}
};
// Director
class ComputerAssembler {
public:
	Computer assembleComputer(ComputerBuilder& builder) {
		builder.buildCPU("Intel i7");
		builder.buildMemory("16GB");
		builder.buildStorage("512GB SSD");
		return builder.getResult();
	}

	Computer assembleLaptop(ComputerBuilder& builder) {
		builder.buildCPU("Ryzen 9");
		builder.buildMemory("21GB");
		builder.buildMemory("16GB");
		builder.buildMemory("1212GB");
		builder.buildStorage("Dysk Tysionc!");
		return builder.getResult();
	}
};

// Product class
class Pizza {
public:
	void setDough(const std::string& dough)
	{
		this->dough = dough;
	}
	void setSauce(const std::string& sauce)
	{
		this->sauce = sauce;
	}
	void setTopping(const std::string& topping)
	{
		this->topping = topping;
	}
	void displayPizza() const
	{
		std::cout << "Pizza with Dough: " << dough
			<< ", Sauce: " << sauce
			<< ", Topping: " << topping << std::endl;
	}
private:
	std::string dough;
	std::string sauce;
	std::string topping;
};
// Abstract builder class
class PizzaBuilder {
public:
	virtual void buildDough() = 0;
	virtual void buildSauce() = 0;
	virtual void buildTopping() = 0;
	Pizza getPizza() const { return pizza; }
protected:
	Pizza pizza;
};
// Concrete builder for a specific type of pizza
class HawaiianPizzaBuilder : public PizzaBuilder {
public:
	void buildDough() override
	{
		pizza.setDough("Pan Dough");
	}
	void buildSauce() override
	{
		pizza.setSauce("Hawaiian Sauce");
	}
	void buildTopping() override
	{
		pizza.setTopping("Ham and Pineapple");
	}
};
// Concrete builder for another type of pizza
class SpicyPizzaBuilder : public PizzaBuilder {
public:
	void buildDough() override
	{
		pizza.setDough("Thin Dough");
	}
	void buildSauce() override
	{
		pizza.setSauce("Spicy Tomato Sauce");
	}
	void buildTopping() override
	{
		pizza.setTopping("Pepperoni and Jalapenos");
	}
};

// Concrete builder for another type of pizza
class MilkowskyPizzaBuilder : public PizzaBuilder {
public:
	void buildDough() override
	{
		pizza.setDough("Thin Dough");
	}
	void buildSauce() override
	{
		pizza.setSauce("Tomato Sauce");
	}
	void buildTopping() override
	{
		pizza.setTopping("Cheese");
	}
};

// Director class that orchestrates the construction
class Cook {
public:
	void makePizza(PizzaBuilder& builder)
	{
		builder.buildDough();
		builder.buildSauce();
		builder.buildTopping();
	}
};


int main() {
	ComputerAssembler assembler;
	DesktopComputerBuilder desktopBuilder;
	Computer desktop = assembler.assembleComputer(desktopBuilder);
	LaptopComputerBuilder laptopBuilder;
	Computer desktop2 = assembler.assembleLaptop(laptopBuilder);
	desktop.display();
	std::cout << std::endl;
	desktop2.display();
	std::cout << std::endl;


	Cook cook;
	HawaiianPizzaBuilder hawaiianBuilder;
	cook.makePizza(hawaiianBuilder);
	Pizza hawaiianPizza = hawaiianBuilder.getPizza();
	hawaiianPizza.displayPizza();

	SpicyPizzaBuilder spicyBuilder;
	cook.makePizza(spicyBuilder);
	Pizza spicyPizza = spicyBuilder.getPizza();
	spicyPizza.displayPizza();

	MilkowskyPizzaBuilder milkowskyBuilder;
	cook.makePizza(milkowskyBuilder);
	Pizza milkowskyPizza = milkowskyBuilder.getPizza();
	milkowskyPizza.displayPizza();
}