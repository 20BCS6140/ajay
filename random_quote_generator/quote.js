const quotetext = document.getElementById("advice");
const authortext = document.getElementById("authorname");
btn = document.querySelector(".new-quote-button");

const searchauthorBtn = document.querySelector(".search-author");

twitterBtn = document.querySelector(".twitter");

instaBtn = document.querySelector(".instagram");

soundBtn = document.querySelector(".sound");

const api_url = "https://api.quotable.io/quotes/random";
// const author_api_url = "https://api.quotable.io/quotes?author=";

async function getquote(url)
{
    // btn.innerText = "Loading Quote...";
    // fetch("https://api.quotable.io/quotes").then(res => res.json()).then(result => {
    // console.log(result.content);
    // quotetext.innerText = result[0].content;
    // authortext.innerText = result[0].author;

    // btn.innerText = "New Quote";

    // });

    btn.innerText = "Loading Quote...";

    var response = await fetch(url);

    var data = await response.json();
    console.log(data);
    quotetext.innerText = data[0].content;
    authortext.innerText =  data[0].author;

    btn.innerText = "New Quote";
    
}

 function search_author()
{
    const author_input = document.querySelector(".authorsearch").value;

    fetch("https://api.quotable.io/quotes?author=${author_input}").then(res => res.json()).then(result => {

        console.log(result);

    });
    

}

btn.addEventListener("click",getquote(api_url));

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







