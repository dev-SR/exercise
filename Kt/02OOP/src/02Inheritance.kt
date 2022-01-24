open class Person(val name: String) {
    init {
        println("This is a person")
    }

    open var age: Int = 1
    open fun doWork() {
        println("Person is doing work")
    }
}

class Students(name: String, val school: String, override var age: Int) : Person(name) {
    init {
        println("This is a student")
    }

    override fun doWork() {
        super.doWork()
        println("Student is doing work")
    }
}

// PolyMorphism
open class Vehicle {
    open fun startEngine() {}
}

class BMWCar() : Vehicle() {
    override fun startEngine() {
        println("BMWCar: start the engine")
        super.startEngine()
    }
}

class AudiCar() : Vehicle() {
    override fun startEngine() {
        println("AudiCar: start the engine")
        super.startEngine()
    }
}

fun startCar(car: Vehicle) {
    car.startEngine()
}

fun startBMWCar(car: BMWCar) {
    car.startEngine()
}

fun startAudiCar(car: AudiCar) {
    car.startEngine()
}

fun main() {
    val x: Person = Students("Mark", "MMC", 10)
    println(x.age)//10
    x.doWork()
    //Person is doing work
    //Student is doing work

    val bmwCar: BMWCar = BMWCar()
    startCar(bmwCar)
    val bmwCar1: Vehicle = BMWCar()
    startCar(bmwCar1)
//    startBMWCar(bmwCar1) [error]
//    startAudiCar(bmwCar) [error]
    startBMWCar(bmwCar)

    val audiCar: Vehicle = AudiCar()
    startCar(audiCar)


}