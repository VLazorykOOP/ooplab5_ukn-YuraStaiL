#include <iostream>
#include <queue>


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

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
    ~TreeNode() {}
};

class BinaryTree {
public:
    TreeNode* root;

    BinaryTree() : root(nullptr) {}
    ~BinaryTree() {}

    void insert(int val);
    void breadthFirstTraversal();
    void reverseInorderTraversal(TreeNode* node);
};

void BinaryTree::insert(int val) {
    if (root == nullptr) {
        root = new TreeNode(val);
        return;
    }

    TreeNode* curr = root;
    while (curr != nullptr) {
        if (val < curr->value) {
            if (curr->left == nullptr) {
                curr->left = new TreeNode(val);
                return;
            }
            curr = curr->left;
        }
        else if (val > curr->value) {
            if (curr->right == nullptr) {
                curr->right = new TreeNode(val);
                return;
            }
            curr = curr->right;
        }
        else {
            std::cout << "Value " << val << " already exists in the tree." << std::endl;
            return;
        }
    }
}

void BinaryTree::breadthFirstTraversal() {
    if (root == nullptr) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        cout << curr->value << " ";

        if (curr->left != nullptr) {
            q.push(curr->left);
        }

        if (curr->right != nullptr) {
            q.push(curr->right);
        }
    }
}

void BinaryTree::reverseInorderTraversal(TreeNode* node) {
    if (node == nullptr) {
        return;
    }

    reverseInorderTraversal(node->right);
    cout << node->value << " ";
    reverseInorderTraversal(node->left);
}



int main() {
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


    cout << "Task 2"

    return 0;
}
