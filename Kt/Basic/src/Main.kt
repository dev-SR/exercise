fun main(){
    //variable deceleration
    var i:Int=10
    println("Value of i is $i")
    i=20
    println("Value of i now is $i")
    //const
    val j= 10.2f
    // j=10.3f can't change

    //data types
    val doubleNumber:Double=20.304
    val floatNumber:Float= 20.2F
    val string:String="Hello World"
    val isBoolean:Boolean=true
    val isNotBoolean:Boolean=false

    //if else
    if (isBoolean) println("True")
    else println("False")

    val fromIf = if(isBoolean) 2 else 4
    println(fromIf)

    //when
    var check =4
    when(check){
        in 1..3 -> println("check is between 1 and 3")
        in 4..10 -> println("check is beween 4 and 10")
        else -> println("not in range")
    }

}