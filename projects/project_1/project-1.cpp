/* Title: project-1.cpp​
 * Abstract: Program which creates a functional vending machine with orders
 * Author: Edgaras Slezas
 * Email: eslezas@csumb.edu
 * Estimate: 11h
 * Date: 02/20/2020
*/

#include <iostream>
using namespace std;

// Max variables
const int AUTOMAT_MAX = 10;
const int ORDER_MAX = 5;

/*
===========================
        CLASSES
===========================
*/

// Food class
class Food {

public:
  Food();
  Food(string name, int calories, double price);
  string getName(); // done
  int getCalories(); // done
  double getPrice(); // done
  void setName(string name); // done
  void setCalories(int calories); // done
  void setPrice(double price); // done
  void display(); // done

private:
  string name;
  int calories;
  double price;
};

// Drink class
class Drink {

public:
  Drink();
  Drink(string name, int calories, double price);
  string getName(); // done
  int getOunces(); // done
  double getPrice(); // done
  void setName(string name); // done
  void setOunces(int ounces); // done
  void setPrice(double price); // done
  void display(); // done

private:
  string name;
  int ounces;
  double price;
};

// Automat class
class Automat {

public:
  Automat();
  bool emptyFood(); // done
  bool emptyDrink(); // done
  void enqueue(Food f); // done
  void enqueue(Drink d); // done
  void dequeueFood(); // done
  void dequeueDrink(); // done
  Food frontFood(); // done
  Drink frontDrink(); // done
  int foodCount(); // done
  int drinkCount(); // done
  int getTotalCalories(); // done
  int getTotalOunces(); // done
  double getTotalPrice(); // done
  void display(); // done

private:
  int myFoodFront;
  int myFoodBack;
  int myDrinkFront;
  int myDrinkBack;
  Food myFood[AUTOMAT_MAX];
  Drink myDrink[AUTOMAT_MAX];
};

// Order class
class Order {

public:
  Order();
  bool emptyFood(); // done
  bool emptyDrink(); // done
  void push(Food f); // done
  void push(Drink d); // done
  void popFood(); // done
  void popDrink(); // done
  Food topFood(); // done
  Drink topDrink(); // done
  int foodCount(); // done
  int drinkCount(); // done
  double getTotalPrice(); // done
  void display(); // done
  void cancel(Automat &); // done
  void purchase(); // done
  int getTotalOrders(); // done

private:
  int myFoodTop;
  int myDrinkTop;
  Food myFood[ORDER_MAX];
  Drink myDrink[ORDER_MAX];
  static int myTotalOrders;
};

int Order::myTotalOrders = 0;

/*
===========================
        CONSTRUCTORS
===========================
*/

Food::Food()
: name("UNKNOWN"), calories(0), price(0) {}

Food::Food(string name, int calories, double price)
: name(name), calories(calories), price(price) {}

Drink::Drink()
: name("UNKNOWN"), ounces(0), price(0) {}

Drink::Drink(string name, int calories, double price)
: name(name), ounces(calories), price(price) {}

Automat::Automat()
: myDrinkFront(0), myDrinkBack(0), myFoodFront(0), myFoodBack(0) {}

Order::Order()
: myDrinkTop(-1), myFoodTop(-1) {
  myTotalOrders++;
}

/*
===========================
      CLASS METHODS
===========================
*/

// Drink getters
string Drink::getName() {
  return name;
}

int Drink::getOunces() {
  return ounces;
}

double Drink::getPrice() {
  return price;
}

// Drink setters
void Drink::setName(string newName) {
  name = newName;
}

void Drink::setOunces(int newOunces) {
  ounces = newOunces;
}

void Drink::setPrice(double newPrice) {
  price = newPrice;
}


// Food getters
string Food::getName() {
  return name;
}

int Food::getCalories() {
  return calories;
}

double Food::getPrice() {
  return price;
}

// Food setters
void Food::setName(string newName) {
  name = newName;
}

void Food::setCalories(int newCalories) {
  calories = newCalories;
}

void Food::setPrice(double newPrice) {
  price = newPrice;
}


void Drink::display() {
  cout << name << ": "<< ounces << " ounces, " << "$" << price << endl;
}

void Food::display() {
  cout << name << ": " << calories << " calories, " << "$" << price << endl;
}




/*
===========================
   AUTOMAT METHODS START
===========================
*/
double Automat::getTotalPrice() {
  double totalPrice = 0;

  for (int i = myDrinkFront; i != myDrinkBack; i = (i + 1) % AUTOMAT_MAX) {
    totalPrice += myDrink[i].getPrice();
  }

  for (int i = myFoodFront; i != myFoodBack; i = (i + 1) % AUTOMAT_MAX) {
    totalPrice += myFood[i].getPrice();
  }

  return totalPrice;
}

void Automat::display() {

  cout << "Automat: " << endl;

  // Display food information
  cout << "  Food: " << endl;
  for (int i = myFoodFront; i != myFoodBack; i = (i + 1) % AUTOMAT_MAX) {
    cout << "      ";
    myFood[i].display();
  }
  cout << "      " << Automat::foodCount() << " food items - " << "Total Calories: " << Automat::getTotalCalories() << endl;

  cout << endl;

  // Display drinks information
  cout << "  Drinks: " << endl;
  for (int i = myDrinkFront; i != myDrinkBack; i = (i + 1) % AUTOMAT_MAX) {
    cout << "      ";
    myDrink[i].display();
  }
  cout << "      " << Automat::drinkCount() << " drinks - " << "Total Ounces: " << Automat::getTotalOunces() << endl;

  cout << endl;
}

/*
===========================
   AUTOMAT METHODS END
===========================
*/



/*
===========================
    AUTOMAT DRINKS START
===========================
*/

int Automat::getTotalOunces() {
  int totalOunces = 0;
  for (int i = myDrinkFront; i != myDrinkBack; i = (i + 1) % AUTOMAT_MAX) {
    totalOunces += myDrink[i].getOunces();
  }
  return totalOunces;
}

int Automat::drinkCount() {
  int count = 0;
  for (int i = myDrinkFront; i != myDrinkBack; i = (i + 1) % AUTOMAT_MAX) {
    count++;
  }
  return count;
}

bool Automat::emptyDrink() {
  return (myDrinkFront == myDrinkBack);
}

void Automat::enqueue(Drink d) {
  int newBack = (myDrinkBack + 1) % AUTOMAT_MAX;
  if (newBack != myDrinkFront) {

    myDrink[myDrinkBack] = d;
    myDrinkBack = newBack;
  } else {
    cerr << "ERROR: Automat is full - can't add new drink\n";
  }
}

Drink Automat::frontDrink() {
  if ( !emptyDrink() ) {
    return (myDrink[myDrinkFront]);
  } else {
    cerr << "ERROR: Automat is empty - returning garbage value\n";
    Drink garbage;
    return garbage;
  }
}

void Automat::dequeueDrink() {
  if ( !emptyDrink() ) {
    myDrinkFront = (myDrinkFront + 1) % AUTOMAT_MAX;
  } else {
    cerr << "ERROR: Automat is empty - can't remove a drink\n";
  }
}

/*
===========================
    AUTOMAT DRINKS END
===========================
*/



/*
===========================
    AUTOMAT FOOD START
===========================
*/

int Automat::getTotalCalories() {
  int totalCalories = 0;
  for (int i = myDrinkFront; i != myDrinkBack; i = (i + 1) % AUTOMAT_MAX) {
    totalCalories += myFood[i].getCalories();
  }
  return totalCalories;
}

int Automat::foodCount() {
  int count = 0;
  for (int i = myFoodFront; i != myFoodBack; i = (i + 1) % AUTOMAT_MAX) {
    count++;
  }
  return count;
}

bool Automat::emptyFood() {
  return (myFoodFront == myFoodBack);
}

void Automat::enqueue(Food f) {
  int newBack = (myFoodBack + 1) % AUTOMAT_MAX;
  if (newBack != myFoodFront) {

    myFood[myFoodBack] = f;
    myFoodBack = newBack;
  } else {
    cerr << "ERROR: Automat is full - can't add new food";
  }
}

Food Automat::frontFood() {
  if ( !emptyDrink() ) {
    return (myFood[myFoodFront]);
  } else {
    cerr << "ERROR: Automat is empty - returning garbage value\n";
    Food garbage;
    return garbage;
  }
}

void Automat::dequeueFood() {
  if ( !emptyFood() ) {
    myFoodFront = (myFoodFront + 1) % AUTOMAT_MAX;
  } else {
    cerr << "ERROR: Automat is empty - can't remove food\n";
  }
}

/*
===========================
    AUTOMAT FOOD END
===========================
*/


/*
===========================
    ORDERS METHODS START
===========================
*/

void Order::display() {

  cout << "Order: " << endl;

  cout << "  Food (" << Order::foodCount() << " items)" << endl;
  for (int i = myFoodTop; i >= 0; i--) {
    cout << "      ";
    myFood[i].display();
  }

  cout << "  Drink (" << Order::drinkCount() << " items)" << endl;
  for (int i = myDrinkTop; i >= 0; i--) {
    cout << "      ";
    myDrink[i].display();
  }

  cout << "  Order total: $" << Order::getTotalPrice() << endl;
  cout << endl;

}

int Order::getTotalOrders() {
  return myTotalOrders;
}

double Order::getTotalPrice() {
  double orderPrice = 0;

  for (int i = myFoodTop; i >= 0; i--) {
    orderPrice += myFood[i].getPrice();
  }

  for (int i = myDrinkTop; i >= 0; i--) {
    orderPrice += myDrink[i].getPrice();
  }

  return orderPrice;
}

void Order::cancel(Automat &a) {

  if ( !emptyFood() ) {
    for (int i = myFoodTop; i >= 0; i--) {
      a.enqueue(myFood[myFoodTop]);
      popFood();
    }
  }

  if ( !emptyDrink() ) {
    for (int i = myDrinkTop; i >= 0; i--) {
      a.enqueue(myDrink[myDrinkTop]);
      popDrink();
    }
  }

}

void Order::purchase() {
  myFoodTop = -1;
  myDrinkTop = -1;
}

/*
===========================
    ORDERS METHODS END
===========================
*/



/*
===========================
    ORDERS DRINK START
===========================
*/

bool Order::emptyDrink() {
  return (myDrinkTop == -1);
}

void Order::push(Drink d) {
  if (myDrinkTop < ORDER_MAX - 1) {

    ++myDrinkTop;
    myDrink[myDrinkTop] = d;

  } else {
    cerr << "ERROR: Order is full - can't add new drinks\n";
    return;
  }
}

Drink Order::topDrink() {
  if ( !emptyDrink()) {
    return (myDrink[myDrinkTop]);
  } else {
    cerr << "ERROR: Order is empty - returning garbage value\n";
    Drink garbage;
    return garbage;
  }
}

void Order::popDrink() {
  if ( !emptyDrink()) {
    myDrinkTop--;
  } else {
    cerr << "ERROR: Order is empty - can't remove a drink\n";
  }
}

int Order::drinkCount() {
  int count = 0;
  for (int i = myDrinkTop; i >= 0; i--) {
    count++;
  }
  return count;
}

/*
===========================
    ORDERS DRINKS END
===========================
*/





/*
===========================
    ORDERS FOOD START
===========================
*/

bool Order::emptyFood() {
  return (myFoodTop == -1);
}

void Order::push(Food f) {
  if (myFoodTop < ORDER_MAX - 1) {

    ++myFoodTop;
    myFood[myFoodTop] = f;

  } else {
    cerr << "ERROR: Order is full - can't add new food\n";
    return;
  }
}

Food Order::topFood() {
  if ( !emptyFood()) {
    return (myFood[myFoodTop]);
  } else {
    cerr << "ERROR: Order is empty - returning garbage value\n";
    Food garbage;
    return garbage;
  }
}

void Order::popFood() {
  if ( !emptyFood()) {
    myFoodTop--;
  } else {
    cerr << "ERROR: Order is empty - can't remove a food\n";
  }
}

int Order::foodCount() {
  int count = 0;
  for (int i = myFoodTop; i >= 0; i--) {
    count++;
  }
  return count;
}

/*
===========================
    ORDERS FOOD END
===========================
*/





/*
===========================
        MAIN CLASS
===========================
*/

int main() {

  Automat a;
  a.enqueue(Food("Let's Potato Chips", 300, 1.50));
  a.enqueue(Food("Mini Donuts", 500, 1));
  a.enqueue(Drink("Coffee", 6, 5.50));
  a.enqueue(Drink("Nacho Drink", 22, 2.50));
  cout << "Starting Automat\n"; a.display();

  Order o;
  o.push(a.frontFood());
  a.dequeueFood();
  o.push(a.frontDrink());
  a.dequeueDrink();
  cout << "Ordered one food, one drink\n";
  o.display();
  a.display();

  cout << "Canceled order\n";
  o.cancel(a);
  o.display();
  a.display();

  cout << "Ordered one food, one drink, purchased\n";
  o.push(a.frontFood());
  a.dequeueFood();
  o.push(a.frontDrink());
  a.dequeueDrink();
  o.purchase();
  o.display();
  a.display();

}
