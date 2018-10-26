[%%raw "const NZlib = require('zlib');"];

[@bs.deriving abstract]
type nzlibOptions = {
  level: int,
  memLevel: int,
};

let normalOptions = nzlibOptions(~level=9, ~memLevel=9);

[@bs.val] external deflateRawSyncBase : (Node.Buffer.t, nzlibOptions) => Node.Buffer.t = "NZlib.deflateRawSync";
let deflateRawSync : (Node.Buffer.t) => Node.Buffer.t = (s) => deflateRawSyncBase(s, normalOptions);

[@bs.val] external inflateRawSyncBase : (Node.Buffer.t) => Node.Buffer.t = "NZlib.inflateRawSync";
let inflateRawSync : (Node.Buffer.t) => Node.Buffer.t = (s) => inflateRawSyncBase(s);
