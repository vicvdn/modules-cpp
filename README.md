# modules-cpp

These modules aim at teaching us the basics of C++ programming language and Object Oriented Programming. We are to conform to the C++98 standard for simplicity's sake (compilation flag to use: ```-std=c++98```).

Our class names have to follow the **UpperCamelCase format**: also known as PascalCase, is a naming convention in programming where the first letter of each word in a compound identifier is capitalized, and there are no spaces or underscores between the words. This format is widely used in various programming languages, including C#, Java, and TypeScript, among others. It is particularly common for class names, method names, and property names to adhere to this convention for readability and consistency across a codebase.

Coplien's Canonic Form, named after Jim Coplien, refers to a specific style of declaring a class in C++. Key characteristics are:
- **Public interface is declared first**
- **Copy Constructors and Assignment Operators**: Explicitly declaring a copy constructor and an assignment operator is encouraged. This makes it clear when and how copying of objects occurs, which is especially important for classes that manage resources.
- **Private Data Members**: All data members of the class are private, encapsulating the internal state of the object. Access to these data members is controlled through public methods (getters and setters), adhering to the principle of data hiding.
- **Constructor Initialization**: Constructors are used to initialize data members, either directly within the class definition or through initialization lists. This ensures that objects are always in a valid state upon creation.
- **Destructor Declaration**: A virtual destructor is declared if the class is intended to be used as a base class. This ensures proper cleanup of derived class objects when they are deleted through a pointer-to-base.

Here's an example of what Coplien's Canonic Form might look like for a simple class:

```cpp
class MyClass {
public:
    // Public interface
    MyClass(); // Constructor
    ~MyClass(); // Destructor
    MyClass(const MyClass& other); // Copy constructor
    MyClass& operator=(const MyClass& rhs); // Assignment operator

    void doSomething();

private:
    // Private data members
    int myData;
};
```

## Important Notions

**1- Les Namespaces:**

Les namespaces sont des espaces de noms qui permettent de regrouper des éléments (variables, fonctions, classes, etc.) sous un même nom. Cela permet d'éviter les conflits de noms et de mieux organiser le code. Les namespaces sont très utiles lorsqu'on utilise des bibliothèques externes ou lorsqu'on travaille sur de gros projets.

**2- Stdio streams:**

Les flux d'entrée/sortie standard (stdio) sont des flux de données qui permettent de lire et d'écrire des données à partir de la console ou d'un fichier. Les flux stdio sont très utiles pour interagir avec l'utilisateur et pour sauvegarder des données sur le disque dur.

exemple:

```cpp
#include <iostream>

int main() {
    char buff[100];

    std::cout << "Hello World!" << std::endl; //std::endl permet de passer à la ligne
    
    std::cout << "Entrez un mot: ";
    std::cin >> buff;
    std::cout << "Vous avez entré: [" << buff << "]" << std::endl;

    return 0;
}
```

**3- Class and instance**

A class in c++ is a user-defined data type that has data members (variables) and member functions (methods). Classes define properties and behaviors of those entities. An instance of a class is an object that is created based on the class definition.

Example:

```cpp
#include <iostream>

class MyClass {
public:
    void doSomething() {
        std::cout << "Doing something..." << std::endl;
    }
};

int main() {
    MyClass myObject;

    myObject.doSomething();

    return 0;
}
```

In the example above, we did not use a constructor nor a destructor. The compiler will generate a default constructor and a default destructor for us. We can also define our own constructor and destructor. It works as such :
    
```cpp 
class MyClass {
public:
    MyClass() {
        std::cout << "Constructor called" << std::endl;
    }

    ~MyClass() {
        std::cout << "Destructor called" << std::endl;
    }

    void doSomething() {
        std::cout << "Doing something..." << std::endl;
    }
};
```
The constructor and destructor can also be defined outside of the class definition. We can then include the .h/.hpp file in a separate cpp file and define them as such:

```cpp
#include <iostream>
#include "MyClass.h"

MyClass::MyClass() {
    std::cout << "Constructor called" << std::endl;
}

MyClass::~MyClass() {
    std::cout << "Destructor called" << std::endl;
}
```

**4- Pointers and references**

Pointers and references are two ways to work with memory addresses in C++. A pointer is a variable that stores the memory address of another variable. A reference is an alias for another variable. Pointers and references are used to pass variables by reference, to work with dynamic memory, and to create data structures like linked lists and trees.

Example:

```cpp
#include <iostream>

int main() {
    int x = 42;
    int* ptr = &x; // Pointer to x
    int& ref = x; // Reference to x

    std::cout << "x = " << x << std::endl;
    std::cout << "ptr = " << *ptr << std::endl;
    std::cout << "ref = " << ref << std::endl;

    *ptr = 21; // Change the value of x through the pointer
    ref = 84; // Change the value of x through the reference

    std::cout << "x = " << x << std::endl;

    return 0;
}
```

**5- The canonical form of Coplien**

The canonical form of Coplien is a way to define a class in C++. It consists of defining the public interface first, followed by the private data members. It also includes the declaration of a constructor, a destructor, a copy constructor, and an assignment operator. This form helps to ensure that the class is well-structured and follows best practices.

Example:

```cpp
class MyClass {
public:
    MyClass(); // Constructor
    ~MyClass(); // Destructor
    MyClass(const MyClass& other); // Copy constructor
    MyClass& operator=(const MyClass& rhs); // Assignment operator
};
```

- **Constructor**: A constructor is a special member function that is called when an object is created. It is used to initialize the object's data members and allocate any necessary resources.
- **Destructor**: A destructor is a special member function that is called when an object is destroyed. It is used to release any resources that were allocated by the object.
- **Copy constructor**: A copy constructor is a special member function that is called when an object is copied. It is used to create a new object that is a copy of an existing object.
- **Assignment operator**: An assignment operator is a special member function that is called when an object is assigned to another object. It is used to copy the data members of one object to another object.

**6- Ad-hoc Polymorphism**

Ad-hoc polymorphism or function overloading is a feature of C++ that allows multiple functions with the same name but different parameter lists to be defined in the same scope. This allows the same function name to be used for different types of arguments, providing a more flexible and expressive way to define functions.


## External resources

- [Public/Private access specfiers within classes definitions](https://www.youtube.com/watch?v=pnhGOznp0UM)
- [String use in c++ handbook](https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring/)
- [Poitners and references in C++ (section 4)](https://cpp.developpez.com/cours/cpp/?page=page_6)
- [Excellent documentation on std::string](https://perso.isima.fr/loic/cpp/string.fr.php)

## Useful functions

- **substr(start index, nb of chars)** : extracts the substring from the start index for the number of characters specified

- **size()** : returns the size of the string

## Remarks

- In C++, non-static member variables cannot be defined or initialized outside of the class declaration or its member function definitions. Non-static member variables belong to individual instances of the class, so they need to be defined within the class declaration itself or initialized within constructors. 

- In C++, the default access specifier for a class is private. This means that if you do not specify an access specifier for a class, all its members will be private by default.

- to free an allocated array of objects you do as such: 

```cpp

Zombie*	zombieHorde( int N, std::string name){
	Zombie*	horde = new Zombie[N];
	
	for (int i = 0; i < N; i++) {
		horde[i] = Zombie(name);
	}
	return (horde);
}

int	main(void) {
	Zombie* 	horde;
	int			N = 5;
	std::string	name = "crackos";

	horde = zombieHorde(N, name);
	for (int i = 0; i < N; i++) {
		horde[i].announce();
	}
	delete[] horde; //necessary [] otherwise segfault
	return 0;
}
```

## CPP01

### ex04:
- Understand how to open a file in c++ and read its content
- Understand how to write to a file in c++

### ex05:
- Understand how pointers to function work in c++ mostly

### ex06:
- Discover switch case in c++

## CPP02

### ex00:

- **Fixed point numbers** are numbers that have a fixed number of digits after the decimal point. They are used to represent fractional numbers in a fixed-point format. Fixed-point numbers are commonly used in embedded systems and real-time applications where floating-point arithmetic is not supported or is too slow. *Example: money is a fixed-point number with 2 decimal places.*

- To define a static constant integer in C++ to store the number of bits of the fractional part with a literal value of 8, you can use the const keyword to declare a static constant. Here is an example of code:

```cpp
class SomeClass {
public:
    static const int FRACTIONAL_BITS = 8;
};
```
In this example:

```static``` means that the variable belongs to the class and not to instances of the class.
const means that the value of the variable cannot be modified after its initialization.
```int FRACTIONAL_BITS = 8``` initializes the variable with the literal value 8.

You can access this constant using ```SomeClass::FRACTIONAL_BITS``` without needing to instantiate SomeClass.

### ex01:
- [Mostafa's notes were super helpful in understanding the concept of fixed point numbers and how  to implement them in C++.](https://drvegapunk.notion.site/Module-02-e736a62ce64a4091baec64782eddb528)

### ex02:

- [To understand how operators overloading works in C++ and how to implement it.](https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c/7531066-utilisez-les-operateurs-de-comparaison)

- Other ressource on the same matter to uderstand the amount of parameters if it is a member function or not: [here](https://cpp.developpez.com/redaction/data/pages/rubrique/cpp/cours/eckel/?page=surcharge-operateurs)

- Best ressource to understand pre/post incrementation and decrementation: [here](https://www.geeksforgeeks.org/increment-and-decrement-operator-overloading-in-c/)

## CPP03

### ex03:

- **Diamond problem**: The diamond problem is an ambiguity that arises when two classes B and C inherit from a class A, and class D inherits from both B and C. If class A has a method that is overridden by B, and C, and D does not override it, then which version of the method does D inherit: that of B, or that of C? The diamond problem is called this way because of the diamond shape that is created when this situation occurs.

- **Virtual inheritance**: Virtual inheritance is a C++ technique that is used to solve the diamond problem. It allows a class to inherit from a base class only once, even if it is inherited by multiple classes in the hierarchy. By using virtual inheritance, you can ensure that there is only one instance of the base class in the inheritance hierarchy, which helps to avoid ambiguity and conflicts. 

- **Protected vs Private**: The protected access specifier allows the members of a class to be accessed by its derived classes. This means that the protected members are visible to the derived classes, but not to the outside world. The private access specifier, on the other hand, restricts access to the members of a class to only that class itself. This means that the private members are not visible to the derived classes or the outside world.

- Useful resource to understand inheritance : [here](https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c/7531561-decouvrez-la-notion-dheritage)

## CPP04

- It is recommended to declare as "virtual" the destructor when working with polymorphisms in C++. This is to ensure that the destructor of the derived class is called when deleting an object through a pointer to the base class.

- **Pure abstract class**: A pure abstract class is a class that contains at least one pure virtual function. A pure virtual function is a function that has no implementation and is declared with the syntax virtual void functionName() = 0;. A pure abstract class cannot be instantiated, but it can be used as a base class for other classes.

- **Concrete class**: A concrete class is a class that can be instantiated and used to create objects. It is a class that has all its member functions implemented and does not contain any pure virtual functions. (contrary to an abstract class)

**Caractéristiques d'une classe concrète donc :**

- **Instanciabilité**: Les classes concrètes peuvent être instanciées, ce qui signifie que vous pouvez créer des objets de ces classes.

- **Implémentation complète**: Toutes les méthodes doivent être définies. Une classe concrète peut hériter de classes abstraites, mais elle doit fournir des implémentations pour toutes les fonctions virtuelles pures héritées afin de pouvoir être instanciée.

- **Aucune méthode virtuelle pure**: Une classe est concrète tant qu'elle ne contient pas de méthode virtuelle pure (méthode définie avec = 0).

## CPP05

**Reminder on abstract base classes and destructors :**

- **Polymorphic Deletion**: If you delete an object of a derived class through a pointer of the base class type, and the base class does not have a virtual destructor, the destructor of the derived class will not be called. This can lead to resource leaks or undefined behavior, as the derived class's resources won't be properly cleaned up.

- **Ensures Proper Cleanup**: Declaring a virtual destructor ensures that when an object is deleted via a base class pointer, the correct destructor (the one from the derived class) is called, allowing for proper resource management and cleanup.

- **Best Practice**: It's a best practice to declare a virtual destructor in any class that is intended to be used polymorphically (i.e., with virtual functions), even if you don't anticipate using it in a polymorphic way right away.


**Exceptions:**

Exceptions are used to pinpoint errors and handle them gracefully in C++. They allow you to separate error handling code from the normal flow of the program, making it easier to write robust and reliable software.

- **Throw**: The throw keyword is used to raise an exception. You can throw any type of object as an exception, but it's common to use standard library exceptions like std::runtime_error or std::logic_error.

- **Try-Catch**: The try-catch block is used to catch exceptions that are thrown in the try block. If an exception is thrown, the catch block is executed, allowing you to handle the error and recover from it.

example :
    
```cpp
    try {
        // Code that may throw an exception
        throw std::runtime_error("An error occurred");
    } 
    catch (const std::exception& e){
        // Handle the exception
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
```

In this module, we had to create our own exceptions, which meant that we had to create a class that inherits from std::exception and override the what() method to return a description of the exception. It looked like this:

```cpp
    class MyException : public std::exception {
            public:
                virtual const char* what() const throw() 
                {
                    return "My custom exception occurred";
                }
    };
```

## CPP06

### ex00:
- **A static method** is a method that belongs to the class itself and not to instances of the class. It can be called without creating an object of the class. Static methods are used to perform operations that do not depend on the state of the object. This is what we are asked to use here because we don't need nor want to create an object of the class to call the method.

example of use:

```cpp
class MyClass {
public:
    static void staticMethod() {
        std::cout << "Static method called" << std::endl;
    }
};

int main() {
    MyClass::staticMethod();

    return 0;
}
```

### ex02:

- In C++, **dynamic_cast** is used for safely casting pointers or references to polymorphic types (i.e., classes that have at least one virtual function). It performs a type-safe downcast or cross-cast at runtime and returns different results based on whether the cast is successful or not.
What dynamic_cast returns:

* When casting to the right type (successful cast):
        If the ***cast is successful, dynamic_cast returns a valid pointer*** (or reference) to the target type. The casted pointer can then be used to access the members of the target class.
* When casting to the wrong type (unsuccessful cast):
        If the ***cast is unsuccessful, the result depends on whether you are working with pointers or references***:

    - **For pointers**:
        If the cast fails, dynamic_cast returns nullptr.

    - **For references**:
        If the cast fails, dynamic_cast throws a std::bad_cast exception, indicating the cast wasn't possible.

example of use:

```cpp
class Base {
public:
    virtual void doSomething() {
        std::cout << "Base class doing something" << std::endl;
    }
};

class Derived : public Base {
public:
    void doSomething() override {
        std::cout << "Derived class doing something" << std::endl;
    }
};

int main() {
    Base* base = new Derived;
    Derived* derived = dynamic_cast<Derived*>(base); // Downcast to derived class

    if (derived) {
        derived->doSomething();
    } else {
        std::cout << "Dynamic cast failed" << std::endl;
    }

    delete base;

    return 0;
}
```

## CPP07

### ex01:

#### 1. Template Definition

```cpp
template <typename T>
void changeToZero(const T & element) {
    T& nonConstElement = const_cast<T&>(element);
    nonConstElement = 0;
}
```

**Template Definition**: The line `template <typename T>` defines a function template that can operate with any type T. This allows the function to be instantiated for different types, such as int, double, std::string, etc.
**Generic Behavior**: The function is designed to handle a wide range of types, providing a single implementation that can be reused.

#### 2. Template Specialization

```cpp
template <>
void changeToZero<std::string>(const std::string & element) {
    std::string& nonConstElement = const_cast<std::string&>(element);
    nonConstElement = "";
}
```

**Template Specialization**: The line `template <>` indicates that this function is a full specialization of the template. This means you are providing a specific implementation for the type std::string.

**Empty Angle Brackets** `(<>)`: The empty angle brackets indicate that this is a specialization and not a new template definition. It tells the compiler that you are overriding the generic template function with a specialized version for a specific type.

### ex02:

In this exercise, we are asked to implement a class template. 

- **Class Template**: A class template is a blueprint for creating classes that can work with any data type. It allows you to define a class that can operate with different types, providing a flexible and reusable solution.

- **Template Parameters**: The line `template <typename T>` defines a class template with a single template parameter T. This parameter can be replaced with any data type when the class is instantiated.

In the subject, it is mentionned we can use a .tpp file to separate the implementation of the template class from its declaration. This is a common practice in C++ to keep the code organized and maintainable. It doesn't have to be compiled, just included at the end of the header file where the class template is declared.

## CPP08

**Containers** are objects that store other objects. They provide a way to group and manage data in a structured way. The C++ Standard Library provides a variety of container classes that offer different features and performance characteristics. 
Vectors, lists, and maps are some of the most commonly used container classes in C++.

They each work with associated member functions that allow you to add, remove, and access elements in the container.

**Iterators** are like pointers that allow you to go through (or "iterate" over) the elements of a container, such as a vector, list, or map, one by one. But some containers are not iterable (such as std::stack).

### ex02:

In this exercise, we are specifically **asked to make std::stack iterable**. ***But how should we proceed? ***

It is important to note that `std::stack` is not directly iterable `because it is an adapter that hides the underlying container`.

- first we need to access the underlying container: `std::stack is built on top of another container` (like `std::deque` or `std::vector`) which actually holds the data. You can access this underlying container by creating a custom subclass or by using a hack to access it directly.
`
```c++
    template <typename T, typename Container = std::deque<T> >
    class IterableStack : public std::stack<T, Container> {
    public:

        typedef typename Container::iterator iterator;

        // Use the type aliases instead of typing out typename Container::iterator
        iterator begin() { return this->c.begin(); }
        iterator end() { return this->c.end(); }
    }
```
`std::stack` is a template class that takes two template parameters: the type of the elements stored in the stack (T) and the type of the underlying container (Container). By default, the underlying container is set to `std::deque<T>`. This means that if no container type is specified when creating an IterableStack, it will use a `std::deque` as the default.

## CPP09

### ex02:

I took a few days to properly understand how the **Ford-Johnson algorithm** works. From what I understood, I first needed to make pairs, then sort them internally, placing the biggest element first. After that I found I had to implement a merge sort algorithm to sort the pairs by the first element in ascending order. Which led me to first :
- search for a proper explanation of a merge sort which I found on [this website](https://www.bbc.co.uk/bitesize/guides/zjdkw6f/revision/5).
- and to then implement an insertion sort once my pairs had been sorted and subdivided into two containers (I chose vectors and deque for this exercise since we were asked to pick two). One containing the biggest elements and the other the smallest ones.

Example of the merge sort algorithm:

### **Example Walkthrough**: 
```Suppose vec contains {{4, 1}, {2, 2}, {5, 3}, {1, 4}, {3, 5}}.```

Initial call: mergeSort(vec, 0, 4).

Split into mergeSort(vec, 0, 2) and mergeSort(vec, 3, 4).
Continue splitting until subarrays have one element.

Merge step starts:
    merge(vec, 0, 0, 1) merges {{4, 1}} and {{2, 2}} to {{2, 2}, {4, 1}}.
    The merging continues up to the full array.
    merge(vec, 0, 1, 2) merges {{2, 2}, {4, 1}} and {{5, 3}} to {{2, 2}, {4, 1}, {5, 3}}.

Final merged and sorted vec is returned.

### Useful resources:

Throughout the entire exercise, these links helped me :
- [FJ algorithm](https://www.linkedin.com/posts/nerraou_ford-johnson-merge-insertion-sort-activity-7076577075712675840-AJ1l)
- [Romain's notes](https://github.com/Tablerase/42_Projects/blob/main/Projects/CPP_Modules/cpp-exercices.md)
