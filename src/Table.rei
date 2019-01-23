[@decco] type rowIndex = { index: int, };

let make:
    (~height: int, ~width: int, ~headerHeight: int, ~rowCount: int,
    ~rowHeight: int, ~rowGetter: rowIndex => Js.Dict.t(string),
    ~rowClassName: rowIndex => string=?, ~onRowClick: TableEvent.t => unit=?,
    ~onRowDoubleClick: TableEvent.t => unit=?, ~onRowMouseOut: TableEvent.t => unit=?,
    ~onRowMouseOver: TableEvent.t => unit=?, ~onRowRightClick: TableEvent.t => unit=?,
    ~className: string=?, 'a) =>
    ReasonReact.component(ReasonReact.stateless, ReasonReact.noRetainedProps,
        ReasonReact.actionless);
