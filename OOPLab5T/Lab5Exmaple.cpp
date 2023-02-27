#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Quadrilateral {
protected:
    double a, b, c, d;

public:
    Quadrilateral(double a, double b, double c, double d) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }

    virtual ~Quadrilateral() {}

    virtual double getPerimeter() {
        return a + b + c + d;
    }

    virtual double getArea() {
        // Формула Герона для обчислення площі
        double s = (a + b + c + d) / 2.0;
        return sqrt((s - a) * (s - b) * (s - c) * (s - d));
    }

    virtual void print() {
        std::cout << "Quadrilateral with sides: " << a << ", " << b << ", " << c << ", " << d << endl;
    }
};

class Square : public Quadrilateral {
public:
    Square(double a) : Quadrilateral(a, a, a, a) {}

    double getPerimeter() override {
        return 4 * a;
    }

    double getArea() override {
        return a * a;
    }

    void print() override {
        std::cout << "Square with side: " << a << endl;
    }
};

class Rectangle : public Quadrilateral {
public:
    Rectangle(double a, double b) : Quadrilateral(a, b, a, b) {}

    double getPerimeter() override {
        return 2 * (a + b);
    }

    double getArea() override {
        return a * b;
    }

    void print() override {
        std::cout << "Rectangle with sides: " << a << ", " << b << endl;
    }
};

//////////////////////////////////////////

#include <iostream>
#include <queue>

using namespace std;


class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BinaryTree {
public:
    BinaryTree() {
        root = NULL;
    }

    void insert(int val) {
        TreeNode* newNode = new TreeNode(val);
        if (root == NULL) {
            root = newNode;
        }
        else {
            TreeNode* currNode = root;
            TreeNode* parentNode = NULL;
            while (currNode != NULL) {
                parentNode = currNode;
                if (val < currNode->val) {
                    currNode = currNode->left;
                }
                else if (val > currNode->val) {
                    currNode = currNode->right;
                }
                else {
                    cout << "Value already exists in the tree." << endl;
                    return;
                }
            }
            if (val < parentNode->val) {
                parentNode->left = newNode;
            }
            else {
                parentNode->right = newNode;
            }
        }
    }

    void preOrder() {
        preOrderTraversal(root);
    }

    void postOrder() {
        postOrderTraversal(root);
    }

private:
    TreeNode* root;

    void preOrderTraversal(TreeNode* currNode) {
        if (currNode != NULL) {
            cout << currNode->val << " ";
            preOrderTraversal(currNode->left);
            preOrderTraversal(currNode->right);
        }
    }

    void postOrderTraversal(TreeNode* currNode) {
        if (currNode != NULL) {
            postOrderTraversal(currNode->left);
            postOrderTraversal(currNode->right);
            cout << currNode->val << " ";
        }
    }
};

/////////////////////

class String {
public:
    String() : str("") { }
    String(const string& s) : str(s) { }
    virtual ~String() { }

    virtual void print(ostream& out) const { out << str << " (string)"; }
    virtual void read(istream& in) { in >> str; }

    String& operator=(const String& other) {
        if (this != &other) {
            str = other.str;
        }
        return *this;
    }

    String(const String& other) : str(other.str) { }

protected:
    string str;
};

class NumberString : public String {
public:
    NumberString() : String("") { }
    NumberString(const string& s) : String(s) { }
    ~NumberString() override { }

    void print(ostream& out) const override { out << str << " (number)"; }
    void read(istream& in) override { in >> str; }

    NumberString& operator=(const NumberString& other) {
        if (this != &other) {
            str = other.str;
        }
        return *this;
    }

    NumberString(const NumberString& other) : String(other.str) { }
};


int main() {
    cout << "Task 1" << endl;

    Quadrilateral* q = new Quadrilateral(2, 3, 4, 5);
    q->print();
    cout << "Perimeter: " << q->getPerimeter() << endl;
    cout << "Area: " << q->getArea() << endl;
    delete q;

    Square* s = new Square(4);
    s->print();
    cout << "Perimeter: " << s->getPerimeter() <<  endl;
    cout << "Area: " << s->getArea() <<  endl;
    delete s;

    Rectangle* r = new Rectangle(3, 5);
    r->print();
    cout << "Perimeter: " << r->getPerimeter() << endl;
    cout << "Area: " << r->getArea() <<  endl;
    delete r;


    cout << "Task 2" << endl;

    BinaryTree bt;
    bt.insert(10);
    bt.insert(7);
    bt.insert(2);
    bt.insert(9);
    bt.insert(2);
    bt.insert(6);
    bt.insert(5);
    bt.insert(11);
    bt.insert(1);

    cout << "Pre-order traversal: ";
    bt.preOrder();
    cout << endl;

    cout << "Post-order traversal: ";
    bt.postOrder();
    cout << endl;


    cout << "Task 3" << endl;
    String s1("Test");
    s1.print(cout);
    cout << endl;
    s1.read(cin);
    s1.print(cout); // вивів вхідний рядок (string)
    String s_copy(s1);

    cout << "\ncopy construct(String) -> ";
    s_copy.print(cout);

    cout << endl << endl;

    NumberString s2("123");
    s2.print(cout); // надрукував "123 (number)"
    cout << endl;

    

    s2.read(cin);
    s2.print(cout);
    cout << endl;
    NumberString s2_copy(s2);

    cout << "copy construct(String) -> ";
    s2_copy.print(cout);

    return 0;
}
