data class User(var name: String, var address: String)

fun main() {
    val user = User("A", "BD")
    val username = with(user) {
        name = "B"
        address = "USA"
        println("$user $this")
        //User(name=B, address=USA) User(name=B, address=USA)
        name// return value
    }
    println(username)//B

    val list = listOf(1, 2, 3, 4, 5)
    with(list) {
        list.filter { it % 2 == 0 }
    }
        .forEach {
            println(it)
        }

}