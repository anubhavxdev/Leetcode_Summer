int numOfUnplacedFruits(int* fruits, int fruitsSize, int* baskets, int basketsSize) {
    int used[100] = {0};
    int unplaced = 0;

    for (int i = 0; i < fruitsSize; i++) {
        int placed = 0;
        for (int j = 0; j < basketsSize; j++) {
            if (!used[j] && baskets[j] >= fruits[i]) {
                used[j] = 1;
                placed = 1;
                break;
            }
        }
        if (!placed) {
            unplaced++;
        }
    }

    return unplaced;
}
