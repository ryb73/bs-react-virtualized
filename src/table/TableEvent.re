[@decco]
type t = {
    event: [@decco.codec Decco.Codecs.magic] ReactEvent.Mouse.t,
    index: int,
    rowData: Js.Json.t
};
