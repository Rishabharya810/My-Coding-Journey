
let id_clicked = 0;
let class_clicked = 0;

function id_func() {

    id_clicked += 1;

    if (id_clicked === 1) {
        alert("Button clicked " + id_clicked + " time, some changes will be made now");

        let heading2 = document.getElementById("head2");
        console.log("Printed using the js", heading2.innerText);
        heading2.innerText = "This heading2 has been modified using JavaScript.";
        console.log("Modified heading text:", heading2.innerText);
        heading2.style.color = "red";
        heading2.style.fontSize = "24px";
        heading2.style.fontWeight = "bold"; 
    }

    if (id_clicked === 2) {
        alert("Button clicked " + id_clicked + " times, nothing more will be changed");
        
        let paragraph = document.getElementById("para");
        console.log("Printed using the js", paragraph.innerText);
        paragraph.innerText = "This paragraph has been modified using JavaScript.";
        console.log("Modified paragraph text:", paragraph.innerText);
        paragraph.style.color = "blue";
        paragraph.style.fontSize = "20px";
        paragraph.style.fontWeight = "bold";
        
    }

    if (id_clicked > 2) {
        alert("Button clicked " + id_clicked + " times nothing more will be changed");
    }

}

function class_func() {

    class_clicked += 1;

    if (class_clicked === 1) {
        alert("Button clicked " + class_clicked + " time, some changes will be made now");

        let item1 = document.getElementsByClassName("item")[0];
        
        let items = document.getElementsByClassName("item");
        items[0].innerText = "This items one has been modified using JavaScript.";

        item1.innerText = "This item one has been modified using JavaScript.";
        item1.style.color = "orange";
        item1.style.fontSize = "20px";
        item1.style.fontWeight = "bold";
        
    }

    if (class_clicked === 2) {
        alert("Button clicked " + class_clicked + " times, some more changes will be made now");

        let item2 = document.getElementsByClassName("item")[1];
        
        item2.innerText = "This item two has been modified using JavaScript.";
        item2.style.color = "green";
        item2.style.fontSize = "20px";
        item2.style.fontWeight = "bold";

    }

    if (class_clicked === 3) {
        alert("Button clicked " + class_clicked + " times, nothing more will be changed");
        
        let item3 = document.getElementsByClassName("item")[2];

        item3.innerText = "This item three has been modified using JavaScript.";
        item3.style.color = "purple";
        item3.style.fontSize = "20px";
        item3.style.fontWeight = "bold";

    
    
    }

    if (class_clicked === 4) {
        alert("Button clicked " + class_clicked + " times, nothing more will be changed");
        let item4 = document.getElementsByClassName("item")[3];

        item4.innerText = "This item four has been modified using JavaScript.";
        item4.style.color = "brown";
        item4.style.fontSize = "20px";
        item4.style.fontWeight = "bold";
        
    
    }


    if (class_clicked > 4) {
        alert("Button clicked " + class_clicked + " times nothing more will be changed");

    }
}
document.getElementById("id_btn").addEventListener("click",id_func);

document.getElementsByClassName("class_btn")[0].addEventListener("click", class_func);