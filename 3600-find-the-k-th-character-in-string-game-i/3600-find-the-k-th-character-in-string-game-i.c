char kthCharacter(int k) {
    int len = 1; 
    while (len < k) {
        len *= 2;
    }

    char c = 'a';

    while (len > 1) {
        len /= 2;
        if (k > len) {
            k -= len;
            c = (c - 'a' + 1) % 26 + 'a'; 
        }
    }

    return c;
}
