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

## Videos cpp - intra

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

