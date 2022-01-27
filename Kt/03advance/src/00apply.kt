fun main() {
    val user = User("A","BD")
    val updatedUser = user.apply {
        name = "B"
        address = "London"
    }
    println(updatedUser)//User(name=B, address=London)
}

//data class User(var name: String, var address: String)