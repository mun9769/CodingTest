function gcd(a, b){
    if(b== 0)
        return a;
    return gcd(b, a %b);
}

function solution(denum1, num1, denum2, num2) {
    var answer = [];
    let under = Math.floor(num1 * num2 / gcd(num1, num2));
    let leftUp = denum1 * Math.floor(under / num1);
    let rightUp = denum2 * Math.floor(under / num2);
    
    let Up = leftUp + rightUp;
    
    let div = gcd(Up, under);
    Up = Math.floor(Up / div);
    under = Math.floor(under / div);
    
    answer.push(Up);
    answer.push(under);
    return answer;
}