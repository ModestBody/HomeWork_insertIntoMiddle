void FineGrainedQueue::insertIntoMiddle(int value, int pos) {
    Node* current = head;
    Node* prev = nullptr;

    for (int i = 0; i < pos - 1; ++i) {
        prev = current;
        current->node_mutex->lock();
        current = current->next;
    }

    Node* newNode = new Node{ value, nullptr, new std::mutex };

    newNode->next = current;
    if (prev != nullptr) {
        prev->next = newNode;
    }
    else {
        head = newNode;
    }

    current->node_mutex->unlock();
    if (prev != nullptr) {
        prev->node_mutex->unlock();
    }
}