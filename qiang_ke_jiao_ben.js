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
