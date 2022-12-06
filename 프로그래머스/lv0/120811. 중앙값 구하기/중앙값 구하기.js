function solution(array) {
    var answer = 0;
    array.sort((a,b) => a- b);
    answer = array[Math.floor(array.length / 2)]; 
    return answer;
}