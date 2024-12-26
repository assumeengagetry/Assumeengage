const kch = '304209030', kxh = '01';//课程号和课序号自己该
const d = document.getElementById("ifra").contentWindow.document;

(() => {
    const tasks = Array(5).fill().map(() => 
        setInterval(() => {
            try {
                d.getElementById("kch").value = kch;
                d.getElementById("queryButton").click();
                
                const checkbox = d.querySelector(`input[id^="${kch}_${kxh}"]`);
                if (checkbox) {
                    checkbox.click();
                    document.getElementById("submitButton").click();
                    tasks.forEach(clearInterval);
                }
            } catch {}
        }, 5)//每5毫秒查询一次，这个可以改，建议不要写1毫秒，容易死人！！
    );
})();

//在edge开发者工具里面找到找到源代码，里面有个‘片段’，在这个‘片段’里复制上这个脚本，将想要的课程号和课序号输入就行。
//这个是个多个课程号课序号的版本
const courses = [
    { kch: '304209030', kxh: '01' },
    { kch: '304209031', kxh: '02' },
    // 添加更多课程...
];
const d = document.getElementById("ifra").contentWindow.document;

(() => {
    const tasks = courses.flatMap(course => 
        Array(3).fill().map(() => 
            setInterval(() => {
                try {
                    d.getElementById("kch").value = course.kch;
                    d.getElementById("queryButton").click();
                    
                    const checkbox = d.querySelector(`input[id^="${course.kch}_${course.kxh}"]`);
                    if (checkbox) {
                        checkbox.click();
                        document.getElementById("submitButton").click();
                        tasks.forEach(clearInterval);
                    }
                } catch {}
            }, 5)
        )
    );
})();
