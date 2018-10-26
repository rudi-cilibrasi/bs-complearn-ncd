let clabel : (string => string) = Filename.basename;
let ccontent : (string => string) = f=>Node.Fs.readFileAsUtf8Sync(f);
let cfolder : (string => string) = Filename.dirname;
type sample = {
    index: int,
    label: string,
    content: string
};

let sample_of_pathname(pathname:string, index:int) = {
    label: clabel(pathname),
    content: ccontent(pathname),
    index
};

let string_of_sample(s:sample) : string = string_of_int(s.index) ++ ": " ++ s.label;
