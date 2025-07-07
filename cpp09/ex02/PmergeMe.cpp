#include "PmergeMe.hpp"

binding createBinding(unsigned int a)
{
	binding bin;

	bin.a = a;
	return (bin);
}

/*
	Basicamente lo que hay que hacer es:
		- Determinar cual de los pares, si uno o el otro es mas grande.
		- Pushear al binding del mayor el pequeño en el campo b.
		- Se mueve el pequeño a ret
		- Se elimina el pequeño de la cadena principal.
		- Se devuelve ret.
*/
listBin splitMainChain(listBin& lb) {
    listBin ret;

    if (lb.size() < 2)
        return ret;

    auto it = lb.begin();
    auto next_it = std::next(it);

    while (next_it != lb.end()) {
        auto first = it;
        auto second = next_it;

        listBinIter smaller, larger;
        if (first->a < second->a) {
            smaller = first;
            larger = second;
        } else {
            smaller = second;
            larger = first;
        }

        // Asignar el valor del menor al campo binding del mayor
        larger->setBindingValue(smaller->a);

        // Insertamos una copia del nodo menor al final de ret
        ret.insert(ret.end(), *smaller);

        // Eliminamos el nodo menor de lb
        lb.erase(smaller);

        // Avanzamos el iterador, teniendo en cuenta que uno ha sido borrado
        if (larger == second) {
            it = lb.begin();
            std::advance(it, std::distance(lb.begin(), second));
        } else {
            it = lb.begin();
            std::advance(it, std::distance(lb.begin(), second) - 1);
        }

        if (it == lb.end())
            break;
        next_it = std::next(it);
    }

    return ret;
}


using namespace std;
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Paso 1: Construcción del árbol
TreeNode* buildCenteredTree(const vector<int>& vec, int start, int end) {
    if (start > end) return nullptr;

    int mid = (start + end) / 2;
    TreeNode* node = new TreeNode(vec[mid]);
    node->left = buildCenteredTree(vec, start, mid - 1);
    node->right = buildCenteredTree(vec, mid + 1, end);
    return node;
}

// Paso 2: Obtener altura del árbol
int getHeight(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

// Paso 3: Imprimir el árbol (bonito)
void printBinaryTree(TreeNode* root) {
    if (!root) {
        cout << "Árbol vacío." << endl;
        return;
    }

    int height = getHeight(root);
    int maxWidth = pow(2, height) * 4;

    queue<TreeNode*> q;
    q.push(root);

    for (int level = 0; level < height; ++level) {
        int levelSize = q.size();
        int spacing = maxWidth / (levelSize + 1);

        // Espaciado inicial
        cout << string(spacing / 2, ' ');

        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front(); q.pop();

            if (node) {
                cout << setw(2) << node->val;
                q.push(node->left);
                q.push(node->right);
            } else {
                cout << " .";
                q.push(nullptr);
                q.push(nullptr);
            }

            cout << string(spacing - 2, ' ');
        }
        cout << endl;
    }
}



///Tu no pienses en nada. Concentrate en implementar un binary search con vectores.

void    printVec(vector<int> &vec) {
    vector<int>::iterator it;
    for (it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
}

void    insertVec(std::vector<int> &vec, 
                  std::vector<int> &b,
                  uint32_t next,
                  uint32_t prev,
                  int new_el) {

    (void) new_el;
    uint32_t span = next - prev;
    while (span--) {
        int pos = (int) (next - 1) / 2; //n es impar
    
        if (b[span] > vec[pos])
        {
            while (pos < vec.size() && pos < next - 1 && b[span] > vec[pos])
                pos++;
        }
        else if (b[span] < vec[pos])
        {
            while (pos >= 0 && b[span] < vec[pos])
                pos--;
            pos++;
        }
        std::cout << "vec pos: " << vec[pos] << " pos : " << pos<< " b span: " << b[span] << std::endl;
        vec.insert(vec.begin() + pos, {b[span]});
        b.erase(b.begin() + span);
    }
}

int main(void) {
    vector<int> vec{3, 8, 16, 45, 555, 800};
    vector<int> b{10, 34, 500, 780};
    insertVec(vec, b, 5, 3, 123);
    printVec(vec);
    printVec(b);
    
    // TreeNode* root = buildCenteredTree(vec, 0, vec.size() - 1);
    // printBinaryTree(root);
}