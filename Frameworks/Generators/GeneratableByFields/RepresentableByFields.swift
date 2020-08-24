#if MIXBOX_ENABLE_IN_APP_SERVICES

/// All classes and structs can be `RepresentableByFields`.
///
/// Even if they don't implement generation from fields themselves, they can be generated
/// somewhere else. For example, non-final classes can not implement their generation, because
/// all protocols like `GeneratableByFields` or `DefaultGeneratorProvider` have associatedtype `Self`,
/// but generators of those classes can be registered in DI.
///
/// This protocol is necessary to constrain generation functions to classes and structs.
/// 1. Enums or primitives can not really be generated by fields.
/// 2. If you want to generate optional, it should be done a little bit differently, for
///    example, you don't initialize value of optional, but you can initialize `Wrapped` value.
///    We need to separate functions for handling classes & structs and other values.
///
/// The actual reason why this protocol was added was a SEGFAULT in Swift when using code below.
///
/// 1. This function was defined in some place:
///
/// ```
/// func stub<R: NetworkRequest>(
///     requestType: R.Type,
///     requestMatcher: @escaping (R) -> Bool,
///     configure: @escaping (TestFailingDynamicLookupConfigurator<R.Method.Result>) throws -> ())
/// ```
///
/// 2. This code was crashing:
///
/// ```
/// networkClientMock.stub(requestType: SomeRequest.self) {
///     $0.someField = $0.generate(type: SomeField.self) {
///         $0.title = "Some title"
/// ```
///
/// 3. This was because `R.Method.Result` was optional and had not `someField` (obviously), but its `Wrapped` type had.
///
/// Ideally Swift should add something to constrain generic type to a something that supports `@dynamicMemberLookup`.
///
/// TODO: Constrain `T` of `Fields<T>` to `RepresentableByFields`. This may require some magic such as type erasure.
///
public protocol RepresentableByFields {}

#endif
