
window.addEventListener('load', function () {

    var ssnInput = document.getElementById('ssn');
    var ssnValid = document.getElementById('ssn-valid');
    var ssnType = document.getElementById('ssn-type');

    ssnInput.addEventListener('input', function () {

        if (ssnInput.value.match(/^[0-9]{8}-[0-9]{4}$/g) && validateSSN(ssnInput.value)) { // Check if it's a valid ssn number
            ssnIsValid(true, 'Personnummer');
        } else if (ssnInput.value.match(/^[0-9]{6}-[0-9]{4}$/g) && validateSSN(ssnInput.value)) {
            ssnIsValid(true, 'Org-nr');
        } else if (ssnInput.length === 0 || ssnInput.value === '') {
            ssnValid.innerHTML = '';
            ssnType.innerHTML = '';
        } else {
            ssnIsValid(false);
        }

    }, { passive: true });

    function ssnIsValid(valid, type) {
        if (valid) {
            ssnValid.innerHTML = 'Valid';
            ssnValid.style.color = 'green';
            ssnType.innerHTML = type;
        } else {
            ssnValid.innerHTML = 'Invalid';
            ssnValid.style.color = 'red';
            ssnType.innerHTML = '';
        }
    }

    function validateSSN(ssn) {
        if (ssn.length === 13) { // Pers-nr

            var controllNum = 0;
            controllNum += addNum(Number(ssn[2]) * 2);
            controllNum += addNum(Number(ssn[3]));
            controllNum += addNum(Number(ssn[4]) * 2);
            controllNum += addNum(Number(ssn[5]));
            controllNum += addNum(Number(ssn[6]) * 2);
            controllNum += addNum(Number(ssn[7]));

            controllNum += addNum(Number(ssn[9]) * 2);
            controllNum += addNum(Number(ssn[10]));
            controllNum += addNum(Number(ssn[11]) * 2);

            if (10 - (controllNum % 10) === Number(ssn[12])) {
                return true;
            }

        } else if (ssn.length === 11) { // Org-nr

            var controllNum = 0;
            controllNum += addNum(Number(ssn[0]) * 2);
            controllNum += addNum(Number(ssn[1]));
            controllNum += addNum(Number(ssn[2]) * 2);
            controllNum += addNum(Number(ssn[3]));
            controllNum += addNum(Number(ssn[4]) * 2);
            controllNum += addNum(Number(ssn[5]));

            controllNum += addNum(Number(ssn[7]) * 2);
            controllNum += addNum(Number(ssn[8]));
            controllNum += addNum(Number(ssn[9]) * 2);

            if (10 - (controllNum % 10) === Number(ssn[10])) {
                return true;
            }

        }

        return false;
    }

    function addNum(num) {
        var str = String(num);
        if (str.length === 2) {
            return (Number(str[0]) + Number(str[1]));
        } else {
            return Number(str);
        }
    }


}, { passive: true });
