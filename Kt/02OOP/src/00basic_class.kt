class User(var email: String, var name: String) {
    fun checkEmail(): Boolean {
        return email.isNotEmpty()
    }

    override fun toString(): String {
        return "User[name=$name, email=$email]"
    }
}

class User1(var email: String, var name: String = "Jhon") {
    override fun toString(): String {
        return "User[name=$name, email=$email]"
    }
}

class User2 {
    var name: String
    var email: String
    var city = ""
    var address: String? = null

    init {
        name = "abc"
        email = "abc@gmail"
    }

    override fun toString(): String {
        return "User[name=$name, email=$email]"
    }
}

class User3(email: String, name: String = "Jhon") {
    var name: String
    var email: String

    init {
        this.name = name
        this.email = email
    }
}
// secondary constructor
class User4{
    var name: String =""
    var email: String =""
    var id:Int = 0

    constructor(name:String){
        this.name = name
    }
    constructor(name:String,email: String){
        this.name = name
        this.email = email
    }

    constructor(name:String,email: String,id:Int):this(name, email){
        this.id = id
    }
}



fun main() {
    val user: User = User("abc@email.com", "abc")
    println(user)//User[name=abc, email=abc@email.com]
    println(user.checkEmail())//true

    val user1: User1 = User1("abc@gmail.com")
    println(user1)//User[name=Jhon, email=abc@gmail.com]

    val user2 = User2()
    println(user2)

    val user3 = User3("abc@gmail.com", "Soikat")
    println(user3)

    val user4 = User4("abc")
    val user44 = User4("abc","abc@gmail.com")
    val user444 = User4("abc","abc@gmail.com",11)


}

