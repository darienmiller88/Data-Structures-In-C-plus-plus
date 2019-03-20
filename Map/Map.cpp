#include "Map.h"

Map::Map() : head(nullptr), len(0){
}

Map::Map(const std::initializer_list<Entry> list) : head(nullptr), len(0) {
	for (auto &elem : list)
		insert(elem);
}

Map::~Map(){
}

int Map::size() const{
	return len;
}

int Map::count(const std::string &key) const{
	return (search(head.get(), key)) ? 1 : 0;
}

bool Map::empty() const{
	return len == 0;
}

void Map::insert(const Entry &entry){
	insertIntoTree(head, entry);
}

int &Map::operator[](const std::string &key){
	Entry entry;

	entry.first = key;
	insert(entry);

	//since newNode already knows where the newly created node is, we will simply return the value of the node the pointer is pointing at.
	return newNode->value;
}

void Map::insertIntoTree(std::unique_ptr<Node> &head, const Entry &entry){
	//when the "head" pointer is a nullptr, which will either be when the binary search tree is empty, or if the left or right
	//Node pointer of a particular Node is a nullptr, create a new Node and set its data accordingly.
	if (head == nullptr) {
		head = std::make_unique<Node>();
		head->key = entry.first;
		head->value = entry.second;
		len++;
		newNode = head.get();//assign the address of the modified Node to that of the newNode pointer. We will need this in order to
		//modify the operator [] function above.
	}

	//if the key of the "Entry" the user passed in is the same as the key of an existing Node, simply change the value of this Node.
	else if (entry.first == head->key) {
		head->value = entry.second;
		newNode = head.get();//assign the address of the modified Node to that of the newNode pointer.
	}

	//if the key of the 
	else if (entry.first < head->key)
		insertIntoTree(head->left, entry);
	else
		insertIntoTree(head->right, entry);
}

void Map::printInOrder(std::ostream &os, Node *root){
	if (root == nullptr)
		return;
	printInOrder(os, root->left.get());
	os << "key: " << root->key << " and value: " << root->value << "\n";
	printInOrder(os, root->right.get());
}

//recursive function to visit every single Node to see if a particular key is in the tree.
bool Map::search(Node *root, const std::string &key) const {
	if (root == nullptr)
		return false;

	if (key == root->key)
		return true;
	else if(key < root->key)
		search(root->left.get(), key);
	else 
		search(root->right.get(), key);
}
std::ostream &operator<<(std::ostream &os, const Map &m){
	m.printInOrder(os, m.head.get());

	return os;
}
