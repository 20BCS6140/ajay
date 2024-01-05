document.addEventListener('DOMContentLoaded', function () {
    getquote();
});



const quotetext = document.getElementById("advice");
const authortext = document.getElementById("authorname");
btn = document.querySelector(".new-quote-button");
const element = document.querySelector(".quote-table");

let randomauthorname ="";  //-------------------------raja shekar's

const searchauthorBtn = document.querySelector(".search-author");

twitterBtn = document.querySelector(".twitter");

instaBtn = document.querySelector(".instagram");

soundBtn = document.querySelector(".sound");



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


    fetch("https://api.quotable.io/quotes?author="+author_input)
    .then(response => response.json())
    .then(data => {

        console.log("ajay");

        if(Object.keys(data.results).length === 0 || author_input === "")
        {
            
            console.log("No Author Found");
            let table_data = `<table class="table">
            <thead>
              <tr>
                <th scope="col">No.</th>
                <th scope="col">Quote</th>
                <th scope="col">Tag</th>
                <th scope="col">Date</th>
              </tr>
            </thead>
            <tbody id="table-data">
            <tr> <th colspan=4 style="text-align:center"> No Data found </th> </tr>
            </tbody>
          </table>`;
            console.log(table_data);
            document.getElementById("table-data").innerHTML = table_data;


        }
        else{
            console.log(data.results);   

            let table_data = `<table class="table">
            <thead>
              <tr>
                <th scope="col">No.</th>
                <th scope="col">Quote</th>
                <th scope="col">Tag</th>
                <th scope="col">Date</th>
              </tr>
            </thead>
            <tbody id="table-data">`;
            let i = 1;

            data.results.map((value) => {

                table_data += 
                `
                <tr>
                <th scope="row"> ${i++} </th>
                <td>${value.content}</td>
                <td>${value.tags}</td>
                <td id="quote-date">${value.dateAdded}</td>
                </tr>`

            });

            table_data+=`
                        </tbody>
                    </table>`

            // console.log(table_data + "Ajay");
            document.getElementById("table-data").innerHTML = table_data;

        }

        author_input.reset();

        


    });
    

}







// ---------------------------Raja shekars--------------------------------------

const showspecificauthor = document.getElementById("authorname");



async function getauthor()
{
    
    fetch("https://api.quotable.io/quotes?author="+randomauthorname)
    .then(response => response.json())
    .then(data => {

        // console.log("ajay");

        if(Object.keys(data.results).length === 0 || randomauthorname === "")
        {
            
            console.log("No Author Found");
            let table_data = `<table class="table">
            <thead>
              <tr>
                <th scope="col">No.</th>
                <th scope="col">Quote</th>
                <th scope="col">Tag</th>
                <th scope="col">Date</th>
              </tr>
            </thead>
            <tbody id="table-data">
            <tr> <th colspan=4 style="text-align:center"> No Data found </th> </tr>
            </tbody>
          </table>`;
            console.log(table_data);
            document.getElementById("table-data").innerHTML = table_data;


        }
        else{
            console.log(data.results);   

            let table_data = `<table class="table">
            <thead>
              <tr>
                <th scope="col">No.</th>
                <th scope="col">Quote</th>
                <th scope="col">Tag</th>
                <th scope="col">Date</th>
              </tr>
            </thead>
            <tbody id="table-data">`;
            let i = 1;

            data.results.map((value) => {

                table_data += `
                <tr>
                <th scope="row"> ${i++} </th>
                <td>${value.content}</td>
                <td>${value.tags}</td>
                <td id="quote-date">${value.dateAdded}</td>
                </tr>`
                

            });

            table_data+=`
                        </tbody>
                    </table>`

            // console.log(table_data + "Ajay");
            document.getElementById("table-data").innerHTML = table_data;

        }

        


    });
}

showspecificauthor.addEventListener("click", function() {
    getauthor();
});


//--------------------------Raja Sekhar's-----------------------------------





btn.addEventListener("click",getquote);

searchauthorBtn.addEventListener("click", function() {

    
    console.log(element.classList.contains("active"));
    if(element.classList.contains("active"))
    {
        search_author();
    }


});



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







