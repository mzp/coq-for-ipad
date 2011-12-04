let output_lock = Mutex.create()

let rec fib n = if n <= 2 then 1 else fib(n-1) + fib(n-2)

let fibtask n =
  while true do
    Mutex.lock output_lock;
    print_int(fib n); print_newline();
    Mutex.unlock output_lock
  done

let _ =
  Thread.create fibtask 28;
  Thread.delay 1.0;
  while true do
    let l = read_line () in
    Mutex.lock output_lock;
    print_string ">> "; print_string l; print_newline();
    Mutex.unlock output_lock
  done
