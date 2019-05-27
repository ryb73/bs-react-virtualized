[@decco] type rowIndex = { index: int };

let make:
    {.
        "children": 'a, "className": option(string),
        "headerHeight": int, "height": int,
        "onRowClick": option(Js.Json.t => unit),
        "onRowDoubleClick": option(Js.Json.t => unit),
        "onRowMouseOut": option(Js.Json.t => unit),
        "onRowMouseOver": option(Js.Json.t => unit),
        "onRowRightClick": option(Js.Json.t => unit),
        "rowClassName": option(Js.Json.t => string), "rowCount":
        int, "rowGetter": Js.Json.t => Js.Dict.t(string),
        "rowHeight": int, "width": int
    } => React.element;
let makeProps:
    (   ~height: int, ~width: int, ~headerHeight: int, ~rowCount: int,
        ~rowHeight: int, ~rowGetter: rowIndex => Js.Dict.t(string),
        ~rowClassName: rowIndex => string=?, ~onRowClick: TableEvent.t => unit=?,
        ~onRowDoubleClick: TableEvent.t => unit=?, ~onRowMouseOut: TableEvent.t => unit=?,
        ~onRowMouseOver: TableEvent.t => unit=?, ~onRowRightClick: TableEvent.t => unit=?,
        ~className: string=?, ~children: 'a, unit
    ) => {.
        "children": 'a, "className": option(string),
        "headerHeight": int, "height": int,
        "onRowClick": option(Js.Json.t => unit),
        "onRowDoubleClick": option(Js.Json.t => unit),
        "onRowMouseOut": option(Js.Json.t => unit),
        "onRowMouseOver": option(Js.Json.t => unit),
        "onRowRightClick": option(Js.Json.t => unit),
        "rowClassName": option(Js.Json.t => string), "rowCount":
        int, "rowGetter": Js.Json.t => Js.Dict.t(string),
        "rowHeight": int, "width": int
    };
