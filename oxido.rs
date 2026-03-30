use std::io;
fn main(){
     let mut input=String::new();
        
     while{
         println!("Ingrese un numero 0 para salir ");
         input.clear();
         io::stdin().read_line(&mut input).is_ok()
             && input.trim()!= "Salir"
     }{
         match input.trim().parse::<i32>(){
            Ok(num) => println!("Ingresaste el numero: {}",num),
            Err(_)=> println!("No es un numero valido"),
        }

    }
    
}