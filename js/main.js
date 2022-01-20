`use strict`;
const XMLHttpRequest = require('xhr2');

const load = (onSuccess) => {
    let xhr = new XMLHttpRequest();
    xhr.responseType = 'json';
    xhr.open(`GET`, `https://api.openweathermap.org/data/2.5/weather?lat=56.317492&lon=44.067198&appid=1b6f09a641acd38d7c029629e51700b6`);
    xhr.send(``);
    xhr.addEventListener('load', function () {
        if (xhr.status === 200) {
            onSuccess(xhr.response);
        }
    });
}


const onSuccessLoad = (data) => {
    console.log(data);
};

load(onSuccessLoad);
