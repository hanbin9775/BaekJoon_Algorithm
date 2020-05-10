var answer = [];

var temp_cmd;

//정보 저장용
//(id, [cur_money, 최대한도])
var dataMap = new Map();

var reqs = ["DEPOSIT 3a 10000", "CREATE 3a 300000", "WITHDRAW 3a 150000", "WITHDRAW 3a 150001"];
var temp_arr = [];

reqs.forEach(e=>{

    temp_cmd = e.split(' ');
    
    //CREATE 일 때
    if(temp_cmd[0]==='CREATE'){
        //id 검사
        if(!dataMap.has(temp_cmd[1])){
            //map에 사용자 id 추가
            dataMap.set(temp_cmd[1],[0,temp_cmd[2]]);
            answer.push(200);
        }
        else{
            answer.push(404);
        }
    }
    //DEPOSIT 일 때
    else if(temp_cmd[0]==='DEPOSIT'){
        //id 검사
        if(!dataMap.has(temp_cmd[1])){
            answer.push(404);
        }
        else{

            dataMap.set(temp_cmd[1],[dataMap.get(temp_cmd[1])[0]+temp_cmd[2] ,dataMap.get(temp_cmd[1][1])]);
            answer.push(200);
        }
    }
    //WITHDRAW
    else{

    }

})


console.log(dataMap.get('3a')[1]);