use std::io;

fn main() {
	let mut func_num = String::new();
	let mut horas = String::new();
	let mut por_hora = String::new();

	io::stdin()
		.read_line(&mut func_num)
		.expect("Falha 1");
	io::stdin()
		.read_line(&mut horas)
		.expect("Falha 2");
	io::stdin()
		.read_line(&mut por_hora)
		.expect("Falha 3");

	let func_num: i32 = func_num.trim().parse().expect("Falha 4");
	let horas: f64 = horas.trim().parse().expect("Falha 5"); // não é possível multiplicar inteiros e ponto flutuante
	let por_hora: f64 = por_hora.trim().parse().expect("Falha 6");

	let salary = horas * por_hora;

	println!("NUMBER = {}",func_num);
	println!("SALARY = U$ {0:.2}",salary);
}