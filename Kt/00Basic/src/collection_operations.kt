data class User(var id: String, var name: String)
data class Product(var id: String, var name: String)
data class CartItem(var productId: String, var qty: Int)
data class CartInfo(var userid: String, var cartItems: List<CartItem>)

val user = User("1", "John")

val products = listOf(
    Product("1", "iPhone"),
    Product("2", "iPad")
)

val cartItems = listOf(
    CartItem(productId = products[0].id, qty = 2),
    CartItem(productId = products[1].id, qty = 1)
)

var cartInfo = CartInfo(user.id, cartItems)

fun main() {
    println("CartInfo: $cartInfo")
    addToCart(user, products[1], 3)
    addToCart(user, Product("10", "Book"), 2)

}

fun addToCart(user: User, product: Product, qty: Int) {
    //find if product already exists in cart
    val cartItem = cartInfo.cartItems.find { it.productId == product.id }
    if (cartItem != null) {
        //update existing cart item
        val updatedCartItems = cartInfo.cartItems.map {
            if (it.productId == product.id) {
                it.copy(qty = it.qty + qty)
            } else {
                it
            }
        }
        cartInfo = cartInfo.copy(cartItems = updatedCartItems)
        println("Updated CartInfo: $cartInfo")
    } else {
        //add new cart item
        val newCartItem = CartItem(product.id, qty)
        val newCartItems = cartInfo.cartItems + newCartItem
        cartInfo = cartInfo.copy(cartItems = newCartItems)
        println("New CartInfo: $cartInfo")
    }
}
