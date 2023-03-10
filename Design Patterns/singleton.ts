// Singleton Pattern:
// => creational design pattern that lets you ensure that a class has only one instance while provide a global access point to this instance.

// => To implemented: 
// 1) make the default constructor private, to prevent other objects from using the new keyword for creating new objects.

// 2) create a static method that acts like constructor, under the hood it calls the private constructor to create an object and save it to a static field. All following calls should retuern the cached object.

class Singleton{
  private static instance:Singleton; 

  private Singlton(){}

  public static getInstance():Singleton{
    if(Singleton.instance === null){
      Singleton.instance = new Singleton();
    }
    return Singleton.instance;
  }
}

const clientCode = () => {
  const s1 = Singleton.getInstance();
  const s2 = Singleton.getInstance();

  if (s1 === s2) {
      console.log('Singleton works, both variables contain the same instance.');
  } else {
      console.log('Singleton failed, variables contain different instances.');
  }
}

clientCode();