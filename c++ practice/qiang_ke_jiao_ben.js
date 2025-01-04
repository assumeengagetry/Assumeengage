const kch = '304209030', kxh = '01';
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
        }, 5)
    );
})();


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