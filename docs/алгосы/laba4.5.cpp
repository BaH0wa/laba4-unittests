#include <iostream>
using namespace std;

bool check_pre_and_in(int* preorder, int* inorder, int& pre_index, int in_start, int in_end) {
    if (in_start > in_end) {
        return true;
    }

    // текущий корень из preorder
    int root_data = preorder[pre_index++];
    
    // Поиск корня по inorder
    int in_index = in_start;

    while (in_index <= in_end && inorder[in_index] != root_data) {
        in_index++;
    }

    if (in_index > in_end) {
        return false;
    }

    // Проверяем поддеревья
    return check_pre_and_in(preorder, inorder, pre_index, in_start, in_index - 1) &&
           check_pre_and_in(preorder, inorder, pre_index, in_index + 1, in_end);
}

bool check_post_and_in(int* postorder, int* inorder, int& post_index, int in_start, int in_end) {
    if (in_start > in_end) {
        return true;
    }

    // текущий корень по postorder
    int root_data = postorder[post_index--];

    // Поиск корня в inorder обходе
    int in_index = in_start;

    while (in_index <= in_end && inorder[in_index] != root_data) { 
        in_index++;
    }

    if (in_index > in_end) {
        return false;
    }

    // Проверяем поддеревья (сначала правое, затем левое)
    return check_post_and_in(postorder, inorder, post_index, in_index + 1, in_end) &&
           check_post_and_in(postorder, inorder, post_index, in_start, in_index - 1);
}

int main() {
    int n;
    cin >> n;

    int* preorder = new int[n];
    int* inorder = new int[n];
    int* postorder = new int[n];

    // подсчет обхоодов
    for (int i = 0; i < n; ++i) {
        cin >> preorder[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> inorder[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> postorder[i];
    }

    // Инициализируем индексы
    int pre_index = 0, post_index = n - 1;

    if (check_pre_and_in(preorder, inorder, pre_index, 0, n - 1) &&
        check_post_and_in(postorder, inorder, post_index, 0, n - 1)) {
            cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}