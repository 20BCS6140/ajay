document.addEventListener('DOMContentLoaded', function () {
    getquote();
});



const quotetext = document.getElementById("advice");
const authortext = document.getElementById("authorname");
btn = document.querySelector(".new-quote-button");

let randomauthorname ="";  //-------------------------raja shekar's

const searchauthorBtn = document.querySelector(".search-author");

twitterBtn = document.querySelector(".twitter");

instaBtn = document.querySelector(".instagram");

soundBtn = document.querySelector(".sound");

// const api_url = "https://api.quotable.io/quotes/random";
// const author_api_url = "https://api.quotable.io/quotes?author=";

function getquote()
{
    btn.innerText = "Loading Quote...";
    fetch("https://api.quotable.io/quotes/random").then(res => res.json()).then(result => {
    console.log(result[0]);
    quotetext.innerText = result[0].content;
    authortext.innerText = result[0].author;
    randomauthorname = result[0].author;

    btn.innerText = "New Quote";

    });

    // btn.innerText = "Loading Quote...";

    // var response = await fetch(url);

    // var data = await response.json();
    // console.log(data);
    // quotetext.innerText = data[0].content;
    // authortext.innerText =  data[0].author;

    // btn.innerText = "New Quote";
    
}

 function search_author()
{
    const author_input = document.querySelector(".authorsearch").value;

    urli = "https://api.quotable.io/quotes?author="+author_input;

    fetch("https://api.quotable.io/quotes?author="+author_input)
    .then(response => response.json())
    .then(data => {

        if(data.results.length < 0 || author_input == "")
        {
            
            console.log("No Author Found");
        }
        else{
            console.log(data);   
        }
        // quotetext.innerText = data.results[0].content;
        // authortext.innerText = data.results[0].author;


    });
    

}







// ---------------------------Raja shekars--------------------------------------

const showspecificauthor = document.getElementById("author_name");
showtext = document.querySelector(".para");


async function getauthor()
{
    // alert("hII");

    fetch("https://api.quotable.io/quotes?author="+randomauthorname)
    .then(response => response.json())
    .then(data => {

        console.log(randomauthorname);
        // console.log(data);
        let text ="";
        for(let i = 0; i < data.results.length;i++)
        {
            // console.log(data.results[i].content);
            text += `<p>${data.results[i].content}<br> <p>` ;

        }

        console.log(text);
        showtext.innerText = text;

        


    });

}

// showspecificauthor.addEventListener("click",getauthor, () => {
//     window.open("test.html","_blank");
// });


//--------------------------Raja Sekhar's-----------------------------------





btn.addEventListener("click",getquote);

searchauthorBtn.addEventListener("click",search_author);



twitterBtn.addEventListener("click", () => {

    window.open("https://twitter.com/intent/tweet?text=" + quotetext.innerText, "_blank");

});


instaBtn.addEventListener("click", () => {

    window.open("https://www.instagram.com/", "_blank");

});

soundBtn.addEventListener("click", () => {

    let speech = new SpeechSynthesisUtterance(quotetext.innerText + " by " + authortext.innerText);
    speechSynthesis.speak(speech);

});







