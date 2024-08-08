// alert('hello');
// const init = () => {
//     document.getElementById('jsworld').innerHTML = "Hello world from javascript";
// }

var productsList = [];

function getProductsList() {
    
    productsList = [
        {name : "Product 1", description : "first", price : "3999"},
        {name : "Product 2", description : "second", price : "7999"},
        {name : "Product 3", description : "third", price : "9999"}
    ]
        init_product_list();
    } 

const init_product_list = () => {
    const div = document.getElementById('productMenu');
    div.innerHTML = `
    <h2>List of Products</h2>
            <table>
                <thead>
                    <tr>
                        <th>Sr No</th>
                        <th>Product Name</th>
                        <th>Description</th>
                        <th>Price</th>
                    </tr>
                </thead>
                <tbody>
                    ${getProductsListHTML()}
                </tbody>
            </table>
    `;
}

const getProductsListHTML = () => {
    var rows = productsList.map((item, index) => {
       return `
            <tr>
                <td>${index}</td>
                <td>${item.name}</td>
                <td>${item.description}</td>
                <td>${item.price}</td>
            </tr>
        `
    });
    return rows;
}


// getProductsListHTML();

// init();


init_product_list();
setTimeout(getProductsList, 5000);


maa di di ****