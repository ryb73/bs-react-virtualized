[@decco] type rowIndex = { index: int, };

module Event: {
    [@decco]
    type t = {
        event: ReactEvent.Mouse.t,
        index: int,
        rowData: Js.Json.t,
    };
};

let make:
    (~height: int, ~width: int, ~headerHeight: int, ~rowCount: int,
    ~rowHeight: int, ~rowGetter: rowIndex => Js.Dict.t(string),
    ~rowClassName: rowIndex => string=?, ~onRowClick: Event.t => unit=?,
    ~onRowDoubleClick: Event.t => unit=?, ~onRowMouseOut: Event.t => unit=?,
    ~onRowMouseOver: Event.t => unit=?, ~onRowRightClick: Event.t => unit=?,
    ~className: string=?, 'a) =>
    ReasonReact.component(ReasonReact.stateless, ReasonReact.noRetainedProps,
        ReasonReact.actionless);
