class ConnectionManager {
    var endPoint: String = ""
    var credentials: Pair<String, String> = Pair("", "")

    fun connect() {
        //make network connection
    }
}
fun main() {
    val user = User("mani","India")

    val updatedUser = user.apply {
        name = "Siva"
        address = "London"
    }.also {
        println(it)
    }

    val connectionManager = ConnectionManager()
        .apply {
            endPoint = "http://endpoint.com"
            credentials = Pair("username", "password")
        }
        .also {
            it.connect()
        }
        .also {
            print("connection is made on ${it.endPoint}")
        }

}

//data class User(var name: String, var address: String)