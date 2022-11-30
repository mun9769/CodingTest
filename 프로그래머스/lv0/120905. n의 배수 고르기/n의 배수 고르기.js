function solution(n, numlist) {
    return numlist
        .filter((ele) => Math.floor(ele % n) === 0);
}