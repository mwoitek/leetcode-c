int hammingDistance(int x, int y)
{
    int dist = 0, val = x ^ y;

    while (val > 0) {
        dist += val & 1;
        val >>= 1;
    }
    return dist;
}
